#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm> // For sorting
#include <iostream>
#include "BaseTask.h"

class User {
private:
    std::string username; // Username of the user
    std::string password; // Password of the user
    std::vector<std::unique_ptr<BaseTask>> tasks;  // Tasks for this user

public:
    // Constructor
    User(const std::string& uname, const std::string& pwd)
        : username(uname), password(pwd) {}

    // Accessors
    const std::string& getUsername() const { return username; }
    bool checkPassword(const std::string& pwd) const { return password == pwd; }

    // Add a task to the user's task list
    void addTask(std::unique_ptr<BaseTask> task) {
        tasks.push_back(std::move(task));
    }

    // Display all tasks
    void displayTasks() const {
        for (const auto& task : tasks) {
            task->displayTask();
        }
    }

    // Display tasks with deadlines and group them
    void displayTasksWithDeadlines() const {
        auto now = std::chrono::system_clock::now();
        auto nearDeadline = now + std::chrono::hours(24); // Tasks due in the next 24 hours

        std::cout << "\nOverdue Tasks:\n";
        for (const auto& task : tasks) {
            if (task->isOverdue()) {
                task->displayTask();
            }
        }

        std::cout << "\nTasks Due Soon (Next 24 Hours):\n";
        for (const auto& task : tasks) {
            if (!task->isOverdue() && task->getDeadline() <= nearDeadline) {
                task->displayTask();
            }
        }

        std::cout << "\nOther Tasks (Sorted by Priority):\n";
        displaySortedTasks();
    }

    // Mark a task as complete by name
    bool markTaskComplete(const std::string& taskName) {
        for (auto& task : tasks) {
            if (task->getName() == taskName) {
                task->markAsComplete();
                return true;
            }
        }
        return false;
    }

    // Notify user about overdue tasks
    void notifyOverdueTasks() const {
        bool hasOverdueTasks = false;

        for (const auto& task : tasks) {
            if (task->isOverdue()) {
                if (!hasOverdueTasks) {
                    std::cout << "\nYou have overdue tasks:\n";
                    hasOverdueTasks = true;
                }
                task->displayTask();
            }
        }

        if (!hasOverdueTasks) {
            std::cout << "You have no overdue tasks.\n";
        }
    }

    // Helper to sort tasks by priority and deadline
    void displaySortedTasks() const {
        std::vector<BaseTask*> sortedTasks;
        for (const auto& task : tasks) {
            sortedTasks.push_back(task.get());
        }

        // Sort by priority and then by deadline
        std::sort(sortedTasks.begin(), sortedTasks.end(), [](BaseTask* a, BaseTask* b) {
            if (a->getPriority() == b->getPriority()) {
                return a->getDeadline() < b->getDeadline(); // Earlier deadline first
            }
            return a->getPriority() > b->getPriority(); // Higher priority first
        });

        for (const auto& task : sortedTasks) {
            task->displayTask();
        }
    }
};

#endif
