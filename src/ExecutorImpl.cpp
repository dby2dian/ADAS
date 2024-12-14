#include "ExecutorImpl.hpp"
#include "cmder/Command.hpp"
#include "cmder/PoseHandler.hpp"
#include "cmder/CmderFactory.hpp"
#include "cmder/Singleton.hpp"

namespace adas {

    Executor* Executor::NewExecutor(const Pose& pose) noexcept {
        return new (std::nothrow) ExecutorImpl(pose);
    }

    ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : poseHandler(pose) {} 

    void ExecutorImpl::Execute(const std::string& commands) noexcept {

        const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);

        std::for_each(cmders.begin(), cmders.end(), [this](const Cmder& cmder) noexcept {
            cmder(poseHandler).DoOperate(poseHandler);  
        });
    }

    void ExecutorImpl::ExecuteSportsCar(const std::string& commands) noexcept {
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmdersSportsCar(commands);

        std::for_each(cmders.begin(), cmders.end(), [this](const Cmder& cmder) noexcept {
            cmder(poseHandler).DoOperate(poseHandler);  
        });
    }

    void ExecutorImpl::ExecuteBus(const std::string& commands) noexcept {
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmdersBus(commands);

        std::for_each(cmders.begin(), cmders.end(), [this](const Cmder& cmder) noexcept {
            cmder(poseHandler).DoOperate(poseHandler);  
        });
    }

    Pose ExecutorImpl::Query() const noexcept {
        return poseHandler.Query();
    }

    bool ExecutorImpl::FastQuery() const noexcept {
        return poseHandler.FastQuery();
    }

    bool ExecutorImpl::ReverseQuery() const noexcept {
        return poseHandler.ReverseQuery();
    }

}