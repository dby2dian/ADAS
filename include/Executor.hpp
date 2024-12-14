#pragma once
#include <string>

namespace adas {

    struct Pose {
        int x;
        int y;
        char heading;
    };

    class Executor {
    public:
        static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'}) noexcept;

        Executor() = default;
        virtual ~Executor() = default;

        Executor(const Executor&) = delete;
        Executor& operator=(const Executor&) = delete;

        virtual void Execute(const std::string& commands) = 0;
        virtual void ExecuteSportsCar(const std::string& commands) = 0;
        virtual void ExecuteBus(const std::string& commands) = 0;
        virtual Pose Query() const noexcept = 0;
        virtual bool FastQuery() const noexcept = 0;
        virtual bool ReverseQuery() const noexcept = 0;
    };

}