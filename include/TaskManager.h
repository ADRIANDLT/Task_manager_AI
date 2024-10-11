#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <memory>
#include "BaseTask.h"

class TaskManager {
private:
    std::vector<std::unique_ptr<BaseTask>> tasks;

public:
    void addTask(std::unique_ptr<BaseTask> task);
    void displayTasks() const;
    void prioritizeTasks();
    
    // New function to display tasks based on priority
    void displayTasksByPriority() const;

    bool markTaskComplete(const std::string& taskName);
};

#endif
