#include <gtest/gtest.h>
#include<memory>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas {

    TEST(ExecutorTest, should_return_init_pose_when_without_command) {
        // Arrange（准备）：创建一个 Executor 对象，初始化 Pose 为 {0, 0, 'E'}
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // Act（执行）：无需额外操作，仅调用 Query

        // Assert（验证）：检查返回的 Pose 是否与预期相等
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command) {

        std::unique_ptr<Executor> executor(Executor::NewExecutor());

        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E) {

        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        executor->Execute("M");
        const Pose target({1, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W) {

        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
        executor->Execute("M");
        const Pose target({-1, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N) {

        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
        executor->Execute("M");
        const Pose target({0, 1, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S) {

        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
        executor->Execute("M");
        const Pose target({0, -1, 'S'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_facing_is_W_given_command_is_L_and_facing_is_N) {

        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
        executor->Execute("L");
        const Pose target({0, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_facing_is_E_given_command_is_L_and_facing_is_S) {

        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
        executor->Execute("L");
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_facing_is_E_given_command_is_R_and_facing_is_N) {

        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
        executor->Execute("R");
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_facing_is_S_given_command_is_R_and_facing_is_E) {

        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        executor->Execute("R");
        const Pose target({0, 0, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
}