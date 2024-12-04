#include "ProgrammingTask.h"
#include <iostream>

ProgrammingTask::ProgrammingTask(std::string name, int priority, int estimatedTime)
    : BaseTask(name, priority, estimatedTime) {}

void ProgrammingTask::displayTask() const {
    std::cout << "AI Task: " << name
              << " | Priority: " << priority
              << " | Deadline: " << deadlineToString() 
              << " | Estimated Time: " << estimatedTime << " hours"
              << " | Completed: " << (isCompleted ? "Yes" : "No")
              << std::endl;
}
