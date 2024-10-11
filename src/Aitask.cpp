#include "AiTask.h"
#include <iostream>

AiTask::AiTask(std::string name, int priority, int estimatedTime)
    : BaseTask(name, priority, estimatedTime) {}

void AiTask::displayTask() const {
    std::cout << "AI Task: " << name
              << " | Priority: " << priority
              << " | Estimated Time: " << estimatedTime << " hours"
              << " | Completed: " << (isCompleted ? "Yes" : "No")
              << std::endl;
}
