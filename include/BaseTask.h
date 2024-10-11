#ifndef BASE_TASK_H
#define BASE_TASK_H

#include <string>
#include <iostream>

class BaseTask {
protected:
    std::string name;
    int priority;
    int estimatedTime; // in hours
    bool isCompleted;  // Flag to mark if the task is completed

public:
    BaseTask(std::string n, int p, int e) // Constrtuctor
        : name(n), priority(p), estimatedTime(e), isCompleted(false) {}

    virtual ~BaseTask() = default; 

    virtual void displayTask() const = 0;

    // Mark the task as completed
    void markAsComplete() {
        isCompleted = true;
    }

    bool isTaskCompleted() const {
        return isCompleted;
    }

    virtual std::string getName() const { return name; }
    virtual int getPriority() const { return priority; }
    virtual int getEstimatedTime() const { return estimatedTime; }
};
#endif
