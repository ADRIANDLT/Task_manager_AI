#include "DevopsTask.h"
#include <iostream>

DevopsTask::DevopsTask(std::string name, int priority, int estimatedTime)
    : BaseTask(name, priority, estimatedTime) {}

void DevopsTask::displayTask() const {
    std::cout << "Devops Task: " << name
              << " | Priority: " << priority
              << " | Deadline: " << deadlineToString() 
              << " | Estimated Time: " << estimatedTime << " hours"
              << " | Completed: " << (isCompleted ? "Yes" : "No")
              << std::endl;
}
