#include <map>
#include <utility>
#include "cmder/PoseHandler.hpp"

namespace adas {
    PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose) {}

    static const std::map<char, std::pair<int, int>> move_map = {
        {'N', {0, 1}},
        {'S', {0, -1}},
        {'E', {1, 0}},
        {'W', {-1, 0}}
    };

    static const std::map<char, int> direction_map = {
        {'N', 3}, {'S', 1}, {'W', 2}, {'E', 0}
    };

    static const std::map<int, char> redirection_map = {
        {3, 'N'}, {1, 'S'}, {2, 'W'}, {0, 'E'}
    };

    void PoseHandler::Forward() noexcept {
        auto it = move_map.find(pose.heading);
        pose.x += it->second.first;
        pose.y += it->second.second;
    }

    void PoseHandler::Backward() noexcept {
        auto it = move_map.find(pose.heading);
        pose.x -= it->second.first;
        pose.y -= it->second.second;
    }

    void PoseHandler::ForwardTwo() noexcept {
        auto it = move_map.find(pose.heading);
        pose.x += 2 * it->second.first;
        pose.y += 2 * it->second.second;
    }

    void PoseHandler::BackwardTwo() noexcept {
        auto it = move_map.find(pose.heading);
        pose.x -= 2 * it->second.first;
        pose.y -= 2 * it->second.second;
    }

    void PoseHandler::TurnLeft() noexcept {
        auto it = direction_map.find(pose.heading);
        pose.heading = redirection_map.find((it->second + 3) % 4)->second;
        
    }

    void PoseHandler::TurnRight() noexcept {
        auto it = direction_map.find(pose.heading);
        pose.heading = redirection_map.find((it->second + 1) % 4)->second;
    }

    void PoseHandler::ReverseTurnLeft() noexcept {
        PoseHandler::TurnRight();
    }

    void PoseHandler::ReverseTurnRight() noexcept {
        PoseHandler::TurnLeft();
    }

    void PoseHandler::BeFast() noexcept {
        fast = !fast;
    }

    bool PoseHandler::isFast() const noexcept {
        return fast;
    } 

    void PoseHandler::BeReverse() noexcept {
        reverse = !reverse;
    }

    bool PoseHandler::isReverse() const noexcept {
        return reverse;
    }

    Pose PoseHandler::Query() const noexcept {
        return pose;
    }

    bool PoseHandler::FastQuery() const noexcept {
        return fast;
    }

    bool PoseHandler::ReverseQuery() const noexcept {
        return reverse;
    }

}