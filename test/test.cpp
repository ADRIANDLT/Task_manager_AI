#include <gtest/gtest.h>
#include "TaskManager.h"
#include "AiTask.h"
#include "HpcTask.h"

// checking if tasks are added correctly
TEST(TaskManagerTests, AddTask) {
    TaskManager manager;
    manager.addTask(std::make_unique<AiTask>("AI mock assignment", 3, 10));
    manager.addTask(std::make_unique<HpcTask>("HPC mock assignment", 2, 5));
    
    // Check if tasks were added (should have 2 tasks)
    testing::internal::CaptureStdout();
    manager.displayTasks();
    std::string output = testing::internal::GetCapturedStdout();

    // Validate if tasks are added
    EXPECT_NE(output.find("AI mock assignment"), std::string::npos);
    EXPECT_NE(output.find("HPC mock assignment"), std::string::npos);
}

// checking if tasks are displayed by priority
TEST(TaskManagerTests, DisplayTasksByPriority) {
    TaskManager manager;
    manager.addTask(std::make_unique<AiTask>("AI Task High", 3, 12));
    manager.addTask(std::make_unique<HpcTask>("HPC Task Medium", 2, 6));
    manager.addTask(std::make_unique<HpcTask>("HPC Task Low", 1, 5));

    // Capture output
    testing::internal::CaptureStdout();
    manager.displayTasksByPriority();
    std::string output = testing::internal::GetCapturedStdout();

    // Validate the order of priorities in the output
    EXPECT_NE(output.find("High Priority Tasks"), std::string::npos);
    EXPECT_NE(output.find("Medium Priority Tasks"), std::string::npos);
    EXPECT_NE(output.find("Low Priority Tasks"), std::string::npos);
}

// checking task completion
TEST(TaskManagerTests, MarkTaskComplete) {
    TaskManager manager;
    manager.addTask(std::make_unique<AiTask>("AI mock assignment", 3, 10));
    manager.addTask(std::make_unique<HpcTask>("HPC mock assignment", 2, 5));

    // Mark the AI Task as complete
    bool taskFound = manager.markTaskComplete("AI mock assignment");
    EXPECT_TRUE(taskFound);  // Makeing sure the task was found and marked complete
}

