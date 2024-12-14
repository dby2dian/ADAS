#pragma once
#include "PoseHandler.hpp"
#include <functional>
#include "ActionGroup.hpp"

namespace adas {

    class MoveCommand final {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
            ActionGroup actionGroup;
            const auto action = poseHandler.isReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;

            if (poseHandler.isFast()) {
                actionGroup.PushAction(action);
            }

            actionGroup.PushAction(action);
            return actionGroup;
        }
    };

    class TurnLeftCommand final {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
            ActionGroup actionGroup;
            const auto action1 = poseHandler.isReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            const auto action2 = poseHandler.isReverse() ? ActionType::REVERSE_TURNLEFT_ACTION : ActionType::TURNLEFT_ACTION;
            if (poseHandler.isFast()) {
                actionGroup.PushAction(action1);
            }

            actionGroup.PushAction(action2);
            return actionGroup;
        }
    };

    class TurnRightCommand final {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
            ActionGroup actionGroup;
            const auto action1 = poseHandler.isReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            const auto action2 = poseHandler.isReverse() ? ActionType::REVERSE_TURNRIGHT_ACTION : ActionType::TURNRIGHT_ACTION;
            if (poseHandler.isFast()) {
                actionGroup.PushAction(action1);
            }

            actionGroup.PushAction(action2);
            return actionGroup;
        }
    };

    class FastCommand final {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
            ActionGroup actionGroup;
            const auto action = ActionType::BE_FAST_ACTION;
            actionGroup.PushAction(action);
            return actionGroup;
        }
    };

    class ReverseCommand final {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
            ActionGroup actionGroup;
            const auto action = ActionType::BE_REVERSE_ACTION;
            actionGroup.PushAction(action);
            return actionGroup;
        }
    };

    class TurnRoundCommand final {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept
        {
            if (poseHandler.isReverse()) {
                return ActionGroup();
            }

            if (poseHandler.isFast()) {
                return ActionGroup({
                    ActionType::FORWARD_1_STEP_ACTION,
                    ActionType::TURNLEFT_ACTION,
                    ActionType::FORWARD_1_STEP_ACTION,
                    ActionType::TURNLEFT_ACTION
                });
            }

            return ActionGroup({
                ActionType::TURNLEFT_ACTION,
                ActionType::FORWARD_1_STEP_ACTION,
                ActionType::TURNLEFT_ACTION
            });
        }
    };


} // namespace adas
