#include "cmder/ActionGroup.hpp"
#include <vector>
#include "cmder/CmderFactory.hpp"

namespace adas {

    class ForwardAction final {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept {
            poseHandler.Forward();
        }
    };

    class BackwardAction final {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept {
            poseHandler.Backward();
        }
    };

    class TurnLeftAction final {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept {
            poseHandler.TurnLeft();
        }
    };

    class ReverseTurnLeftAction final {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept {
            poseHandler.ReverseTurnLeft();
        }
    };

    class TurnRightAction final {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept {
            poseHandler.TurnRight();
        }
    };

    class ReverseTurnRightAction final {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept {
            poseHandler.ReverseTurnRight();
        }
    };

    class BeFastAction final {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept {
            poseHandler.BeFast();
        }
    };

    class BeReverseAction final {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept {
            poseHandler.BeReverse();
        }
    };

    class ForwardTwoAction final {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept {
            poseHandler.ForwardTwo();
        }
    };

    class BackwardTwoAction final {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept {
            poseHandler.BackwardTwo();
        }
    };

    ActionGroup::ActionGroup(const std::list<ActionType>& actions) noexcept : actions(actions) {}

    void ActionGroup::PushAction(const ActionType ActionType) noexcept {
        actions.push_back(ActionType);
    }

    void ActionGroup::DoOperate(PoseHandler& poseHandler) const noexcept {
        static std::vector<std::function<void(PoseHandler&)>> actionVec = {
            ForwardAction(), BackwardAction(), TurnLeftAction(), ReverseTurnLeftAction(),
            TurnRightAction(), ReverseTurnRightAction(), BeFastAction(), BeReverseAction(),
            ForwardTwoAction(), BackwardTwoAction()
        };

        std::for_each(actions.begin(), actions.end(), [&poseHandler](const ActionType actionType) mutable noexcept {
            actionVec[static_cast<uint16_t>(actionType)](poseHandler);
        });
    }

}