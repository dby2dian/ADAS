#pragma once

#include <list>
#include "PoseHandler.hpp"

namespace adas
{
    // 定义原子操作的类型（动作）
    enum class ActionType : uint16_t {
        FORWARD_1_STEP_ACTION = 0,  // 前进一步
        BACKWARD_1_STEP_ACTION = 1,     // 后退一步
        TURNLEFT_ACTION = 2,            // 左转
        REVERSE_TURNLEFT_ACTION = 3,    // 反向左转
        TURNRIGHT_ACTION = 4,           // 右转
        REVERSE_TURNRIGHT_ACTION = 5,   // 反向右转
        BE_FAST_ACTION = 6,             // 加速
        BE_REVERSE_ACTION = 7,          // 倒车
        FORWARD_2_STEP_ACTION = 8,
        BACKWARD_2_STEP_ACTION = 9
    };

    class ActionGroup final {
    public:
        ActionGroup(void) = default;
        explicit ActionGroup(const std::list<ActionType>& actions) noexcept;
        ~ActionGroup() = default;

    public:
        void PushAction(const ActionType ActionType) noexcept;
        void DoOperate(PoseHandler& poseHandler) const noexcept;

    private:
        std::list<ActionType> actions;
    };
}