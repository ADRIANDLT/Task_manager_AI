#ifndef AI_TASK_H
#define AI_TASK_H

#include "BaseTask.h"

class AiTask : public BaseTask {
public:
    AiTask(std::string name, int priority, int estimatedTime);
    
    void displayTask() const override;  // Declaration only
};

#endif
