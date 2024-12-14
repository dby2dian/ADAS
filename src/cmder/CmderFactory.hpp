#pragma once
#include <functional>
#include <list>
#include <unordered_map>
#include "Command.hpp"
#include "CommandSportsCar.hpp"
#include "CommandBus.hpp"
#include "ActionGroup.hpp"

namespace adas {

using Cmder = std::function<ActionGroup(PoseHandler& poseHandler)>;
using CmderList = std::list<Cmder>;

class CmderFactory final {
public:
    CmderFactory(void) noexcept = default;
    ~CmderFactory(void) noexcept = default;

    CmderFactory(const CmderFactory&) noexcept = delete;
    CmderFactory& operator=(const CmderFactory&) noexcept = delete;

    // 根据输入的命令字符串生成命令，并返回一个命令列表
    CmderList GetCmders(const std::string& commands) const noexcept;
    CmderList GetCmdersSportsCar(const std::string& commands) const noexcept;
    CmderList GetCmdersBus(const std::string& commands) const noexcept;


private:
    std::string ParseCommandString(std::string_view commands) const noexcept;
    void ReplaceAll(std::string& inout, std::string_view what, std::string_view with) const noexcept;

private:
    // 存储命令字符与命令函数的映射关系
    const std::unordered_map<char, Cmder> cmderMap {
        {'M', MoveCommand()},
        {'L', TurnLeftCommand()},
        {'R', TurnRightCommand()},
        {'F', FastCommand()},
        {'B', ReverseCommand()},
        {'Z', TurnRoundCommand()}
    };

    const std::unordered_map<char, Cmder> cmderMapSportsCar {
        {'M', MoveCommandSportsCar()},
        {'L', TurnLeftCommandSportsCar()},
        {'R', TurnRightCommandSportsCar()},
        {'F', FastCommandSportsCar()},
        {'B', ReverseCommandSportsCar()},
        {'Z', TurnRoundCommandSportsCar()}
    };

    const std::unordered_map<char, Cmder> cmderMapBus {
        {'M', MoveCommandBus()},
        {'L', TurnLeftCommandBus()},
        {'R', TurnRightCommandBus()},
        {'F', FastCommandBus()},
        {'B', ReverseCommandBus()},
        {'Z', TurnRoundCommandBus()}
    };

};

}  // namespace adas
