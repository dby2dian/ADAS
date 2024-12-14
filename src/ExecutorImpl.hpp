#pragma once
#include<memory>
#include<unordered_map>
#include "Executor.hpp"
#include "cmder/PoseHandler.hpp"
#include "cmder/Command.hpp"

namespace adas {

    class ExecutorImpl final : public Executor {
    public:
        explicit ExecutorImpl(const Pose& pose) noexcept;
        ~ExecutorImpl() noexcept = default;

        ExecutorImpl(const ExecutorImpl&) = delete;
        ExecutorImpl& operator=(const ExecutorImpl&) = delete;

    public:
        void Execute(const std::string& commands) noexcept override;  // 实现命令执行逻辑
        void ExecuteSportsCar(const std::string& commands) noexcept override;
        void ExecuteBus(const std::string& commands) noexcept override;
        Pose Query() const noexcept override;
        bool FastQuery() const noexcept override;
        bool ReverseQuery() const noexcept override;

    private:
        PoseHandler poseHandler;
        
    };

}  // namespace adas
