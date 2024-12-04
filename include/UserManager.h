#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <string>
#include <unordered_map>
#include <memory>
#include "User.h"

class UserManager {
private:
    std::unordered_map<std::string, std::shared_ptr<User>> users;  // Maps usernames to User objects
    std::shared_ptr<User> currentUser;  // Currently logged-in user

public:
    bool registerUser(const std::string& username, const std::string& password) {
        if (users.find(username) != users.end()) {
            return false;  // User already exists
        }
        users[username] = std::make_shared<User>(username, password);
        return true;
    }

    bool loginUser(const std::string& username, const std::string& password) {
        auto it = users.find(username);
        if (it != users.end() && it->second->checkPassword(password)) {
            currentUser = it->second;
            return true;
        }
        return false;
    }

    void logoutUser() {
        currentUser = nullptr;
    }

    std::shared_ptr<User> getCurrentUser() const {
        return currentUser;
    }

    bool isLoggedIn() const {
        return currentUser != nullptr;
    }
};

#endif
