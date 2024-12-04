#ifndef BASE_TASK_H
#define BASE_TASK_H

#include <string>
#include <iostream>
#include <chrono>
#include <iomanip> // For formatting output

class BaseTask {
protected:
    std::string name; // Task name
    int priority; // Task priority (1 = Low, 3 = High)
    std::chrono::system_clock::time_point deadline; // Task deadline
    int estimatedTime; // Estimated time to complete the task (in hours)
    bool isCompleted;  // Flag to mark if the task is completed

public:
    // Constructor
    BaseTask(std::string n, int p, int e) 
        : name(n), priority(p), estimatedTime(e), isCompleted(false) {}

    virtual ~BaseTask() = default;

    // Pure virtual function to display task details
    virtual void displayTask() const = 0;

    // Mark the task as completed
    void markAsComplete() {
        isCompleted = true;
    }

    // Check if the task is completed
    bool isTaskCompleted() const {
        return isCompleted;
    }

    // Accessors for task attributes
    virtual std::string getName() const { return name; }
    virtual int getPriority() const { return priority; }
    virtual int getEstimatedTime() const { return estimatedTime; }

    // Deadline-related methods
    void setDeadline(const std::chrono::system_clock::time_point& dl) {
        deadline = dl;
    }

    std::chrono::system_clock::time_point getDeadline() const {
        return deadline;
    }

    bool isOverdue() const {
        return std::chrono::system_clock::now() > deadline;
    }

    // Convert deadline to a human-readable string
    std::string deadlineToString() const {
        std::time_t deadlineTime = std::chrono::system_clock::to_time_t(deadline);
        char buffer[26]; // Buffer to hold formatted time
        ctime_r(&deadlineTime, buffer); // Thread-safe version of ctime
        buffer[24] = '\0'; // Remove trailing newline
        return std::string(buffer);
    }
};

#endif
