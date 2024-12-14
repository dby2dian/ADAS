#include "cmder/CmderFactory.hpp"

namespace adas {

CmderList CmderFactory::GetCmders(const std::string& commands) const noexcept {
    CmderList cmders;  

    for (const auto cmd : ParseCommandString(commands)) {
        const auto it = cmderMap.find(cmd);
        
        if (it != cmderMap.end()) {
            cmders.push_back(it->second);
        }
    }

    return cmders;
}

CmderList CmderFactory::GetCmdersSportsCar(const std::string& commands) const noexcept {
    CmderList cmders;  

    for (const auto cmd : ParseCommandString(commands)) {
        const auto it = cmderMapSportsCar.find(cmd);
        
        if (it != cmderMapSportsCar.end()) {
            cmders.push_back(it->second);
        }
    }

    return cmders;
}

CmderList CmderFactory::GetCmdersBus(const std::string& commands) const noexcept {
    CmderList cmders;  

    for (const auto cmd : ParseCommandString(commands)) {
        const auto it = cmderMapBus.find(cmd);
        
        if (it != cmderMapBus.end()) {
            cmders.push_back(it->second);
        }
    }

    return cmders;
}

std::string CmderFactory::ParseCommandString(std::string_view commands) const noexcept {
    std::string result(commands);
    
    // 替换 "TR" 为 "Z"
    ReplaceAll(result, "TR", "Z");
    
    return result;
}

void CmderFactory::ReplaceAll(std::string& inout, std::string_view what, std::string_view with) const noexcept {
    for (std::string::size_type pos{}; inout.npos != (pos = inout.find(what.data(), pos, what.length())); pos += with.length()) {
        inout.replace(pos, what.length(), with.data(), with.length());
    }
}

}  // namespace adas
