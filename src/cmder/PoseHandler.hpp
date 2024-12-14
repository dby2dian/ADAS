#pragma once
#include "Executor.hpp"

namespace adas {
    class PoseHandler final {

    public:
        PoseHandler(const Pose& pose) noexcept;
        PoseHandler(const PoseHandler&) = delete;
        PoseHandler& operator=(const PoseHandler&) = delete;
    
    public:
        Pose Query(void) const noexcept;                   // 查询当前位置信息
        bool FastQuery(void) const noexcept;
        bool ReverseQuery(void) const noexcept;

        bool isFast(void) const noexcept;
        bool isReverse(void) const noexcept;

        void Forward(void) noexcept;
        void Backward(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;
        void ReverseTurnLeft(void) noexcept;
        void ReverseTurnRight(void) noexcept;
        void BeFast(void) noexcept;
        void BeReverse(void) noexcept;
        void ForwardTwo(void) noexcept;
        void BackwardTwo(void) noexcept;

    private:
        Pose pose;  // 存储当前的位置信息
        bool fast = false;
        bool reverse = false;
    };
}