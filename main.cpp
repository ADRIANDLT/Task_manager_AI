#include <iostream>
#include <limits>
#include <memory>
#include "UserManager.h"
#include "AiTask.h"
#include "HpcTask.h"
#include "ProgrammingTask.h"
#include "DevopsTask.h"

int main() {
    UserManager userManager;
    bool running = true;

    while (running) {
        int option;

        // Menu changes based on login status
        if (!userManager.isLoggedIn()) {
            // Registration/Login Menu
            std::cout << "\nWelcome to Task Manager\n";
            std::cout << "1. Register\n";
            std::cout << "2. Login\n";
            std::cout << "3. Exit\n";
            std::cout << "Enter option: ";
            std::cin >> option;

            if (option == 1) {
                // Register a new user
                std::string username, password;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;

                if (userManager.registerUser(username, password)) {
                    std::cout << "User registered successfully.\n";
                } else {
                    std::cout << "Username already exists. Try a different one.\n";
                }

            } else if (option == 2) {
                // Login an existing user
                std::string username, password;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;

                if (userManager.loginUser(username, password)) {
                    std::cout << "Login successful. Welcome, " << username << "!\n";
                } else {
                    std::cout << "Invalid username or password.\n";
                }

            } else if (option == 3) {
                // Exit the program
                running = false;
            } else {
                std::cout << "Invalid option. Please try again.\n";
            }
        } else {
            // Logged-in User Menu
            std::cout << "\nTask Manager Menu:\n";
            std::cout << "1. Add AI Task\n";
            std::cout << "2. Add HPC Task\n";
            std::cout << "3. Add Programming Task\n";
            std::cout << "4. Add DevOps Task\n";
            std::cout << "5. Display Tasks by Priority\n";
            std::cout << "6. Mark Task as Complete\n";
            std::cout << "7. Logout\n";
            std::cout << "8. Exit\n";
            std::cout << "Enter option: ";
            std::cin >> option;

            auto currentUser = userManager.getCurrentUser();

            if (option >= 1 && option <= 4) {
                // Common input for all tasks
                std::string name;
                int priority = 0, estimatedTime;

                std::cout << "Enter Task name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                std::getline(std::cin, name);

                // Ensure priority is 1, 2, or 3
                while (priority < 1 || priority > 3) {
                    std::cout << "Enter priority (1 = Low, 2 = Medium, 3 = High): ";
                    std::cin >> priority;
                    if (priority < 1 || priority > 3) {
                        std::cout << "Invalid priority. Please enter a value between 1 and 3.\n";
                    }
                }

                std::cout << "Enter estimated time (hours): ";
                std::cin >> estimatedTime;

                // Add the appropriate task based on user input
                switch (option) {
                    case 1:
                        currentUser->addTask(std::make_unique<AiTask>(name, priority, estimatedTime));
                        break;
                    case 2:
                        currentUser->addTask(std::make_unique<HpcTask>(name, priority, estimatedTime));
                        break;
                    case 3:
                        currentUser->addTask(std::make_unique<ProgrammingTask>(name, priority, estimatedTime));
                        break;
                    case 4:
                        currentUser->addTask(std::make_unique<DevopsTask>(name, priority, estimatedTime));
                        break;
                }
                std::cout << "Task added successfully.\n";

            } else if (option == 5) {
                // Display tasks sorted by priority
                currentUser->displayTasks();

            } else if (option == 6) {
                // Mark a task as complete
                std::string taskName;
                std::cout << "Enter task name to mark as complete: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                std::getline(std::cin, taskName);

                if (currentUser->markTaskComplete(taskName)) {
                    std::cout << "Task marked as complete.\n";
                } else {
                    std::cout << "Task not found.\n";
                }

            } else if (option == 7) {
                userManager.logoutUser();
                std::cout << "You have been logged out.\n";

            } else if (option == 8) {
                running = false;

            } else {
                std::cout << "Invalid option. Please try again.\n";
            }
        }
    }

    return 0;
}
