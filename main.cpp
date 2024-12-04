#include <iostream>
#include <limits>
#include <memory>
#include <chrono>
#include "UserManager.h"
#include "AiTask.h"
#include "HpcTask.h"
#include "ProgrammingTask.h"
#include "DevopsTask.h"

// Function to get a valid menu option
int getMenuOption(int min, int max) {
    int option;
    while (true) {
        std::cin >> option;
        if (std::cin.fail() || option < min || option > max) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else {
            return option;
        }
    }
}

// Function to get a valid deadline from the user
std::chrono::system_clock::time_point getDeadlineInput() {
    int year, month, day;
    while (true) {
        std::cout << "Enter deadline (YYYY MM DD): ";
        std::cin >> year >> month >> day;

        // Validate year, month, and day
        if (std::cin.fail() || year < 1900 || month < 1 || month > 12 || day < 1 || day > 31) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid date. Please enter a valid date (YYYY MM DD).\n";
        } else {
            std::tm deadlineTm = {};
            deadlineTm.tm_year = year - 1900;
            deadlineTm.tm_mon = month - 1;
            deadlineTm.tm_mday = day;

            std::time_t deadlineTime = std::mktime(&deadlineTm);
            if (deadlineTime == -1) {
                std::cout << "Invalid date. Please try again.\n";
            } else {
                return std::chrono::system_clock::from_time_t(deadlineTime);
            }
        }
    }
}

int main() {
    UserManager userManager;
    bool running = true;

    while (running) {
        int option;

        if (!userManager.isLoggedIn()) {
            // Registration/Login Menu
            std::cout << "\nWelcome to Task Manager\n";
            std::cout << "1. Register\n";
            std::cout << "2. Login\n";
            std::cout << "3. Exit\n";
            std::cout << "Enter option: ";
            option = getMenuOption(1, 3);

            if (option == 1) {
                std::string username, password;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;

                if (username.empty() || password.empty()) {
                    std::cout << "Error: Username and password cannot be empty.\n";
                } else if (userManager.registerUser(username, password)) {
                    std::cout << "User registered successfully.\n";
                } else {
                    std::cout << "Error: Username already exists.\n";
                }

            } else if (option == 2) {
                std::string username, password;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;

                if (!userManager.loginUser(username, password)) {
                    std::cout << "Error: Invalid username or password.\n";
                } else {
                    std::cout << "Login successful.\n";

                    // Notify user of overdue tasks
                    auto currentUser = userManager.getCurrentUser();
                    currentUser->notifyOverdueTasks();
                }

            } else if (option == 3) {
                running = false;
            }

        } else {
            // Logged-in User Menu
            std::cout << "\nTask Manager Menu:\n";
            std::cout << "1. Add AI Task\n";
            std::cout << "2. Add HPC Task\n";
            std::cout << "3. Add Programming Task\n";
            std::cout << "4. Add DevOps Task\n";
            std::cout << "5. Display Tasks with Deadlines\n";
            std::cout << "6. Mark Task as Complete\n";
            std::cout << "7. Logout\n";
            std::cout << "8. Exit\n";
            std::cout << "Enter option: ";
            option = getMenuOption(1, 8);

            auto currentUser = userManager.getCurrentUser();

            if (option >= 1 && option <= 4) {
                // Task creation logic
                std::string name;
                int priority = 0, estimatedTime;

                std::cout << "Enter Task name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);

                while (priority < 1 || priority > 3) {
                    std::cout << "Enter priority (1 = Low, 2 = Medium, 3 = High): ";
                    std::cin >> priority;
                    if (priority < 1 || priority > 3) {
                        std::cout << "Invalid priority. Please enter a value between 1 and 3.\n";
                    }
                }

                std::cout << "Enter estimated time (hours): ";
                std::cin >> estimatedTime;

                auto deadline = getDeadlineInput();

                std::unique_ptr<BaseTask> task;
                switch (option) {
                    case 1:
                        task = std::make_unique<AiTask>(name, priority, estimatedTime);
                        break;
                    case 2:
                        task = std::make_unique<HpcTask>(name, priority, estimatedTime);
                        break;
                    case 3:
                        task = std::make_unique<ProgrammingTask>(name, priority, estimatedTime);
                        break;
                    case 4:
                        task = std::make_unique<DevopsTask>(name, priority, estimatedTime);
                        break;
                }

                task->setDeadline(deadline);
                currentUser->addTask(std::move(task));
                std::cout << "Task added successfully.\n";

            } else if (option == 5) {
                currentUser->displayTasksWithDeadlines();

            } else if (option == 6) {
                std::string taskName;
                std::cout << "Enter task name to mark as complete: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, taskName);

                if (currentUser->markTaskComplete(taskName)) {
                    std::cout << "Task marked as complete.\n";
                } else {
                    std::cout << "Error: Task \"" << taskName << "\" not found.\n";
                }

            } else if (option == 7) {
                userManager.logoutUser();
                std::cout << "You have been logged out.\n";

            } else if (option == 8) {
                running = false;
            }
        }
    }

    return 0;
}
