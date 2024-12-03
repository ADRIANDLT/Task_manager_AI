#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <memory>
#include "BaseTask.h"

class User {
private:
    std::string username;
    std::string password;
    std::vector<std::unique_ptr<BaseTask>> tasks;  // Tasks for this user

public:
    User(const std::string& uname, const std::string& pwd)
        : username(uname), password(pwd) {}

    const std::string& getUsername() const { return username; }
    bool checkPassword(const std::string& pwd) const { return password == pwd; }

    void addTask(std::unique_ptr<BaseTask> task) {
        tasks.push_back(std::move(task));
    }

    void displayTasks() const {
        for (const auto& task : tasks) {
            task->displayTask();
        }
    }

    bool markTaskComplete(const std::string& taskName) {
        for (auto& task : tasks) {
            if (task->getName() == taskName) {
                task->markAsComplete();
                return true;
            }
        }
        return false;
    }
};

#endif
