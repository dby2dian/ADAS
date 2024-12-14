#include <gtest/gtest.h>
#include<memory>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas {

    TEST(ExecutorReverseTest, should_return_initpose_given_command_is_FFB_and_facing_is_N) {
        // Arrange（准备）：创建一个 Executor 对象，初始化 Pose 为 {0, 0, 'N'}
        std::unique_ptr<Executor> executor(Executor::NewExecutor());

        // Act（执行）：无需额外操作，仅调用 Query
        executor->Execute("FFB");
        // Assert（验证）：检查返回的 Pose 是否与预期相等
        const Pose target({0, 0, 'N'});
        const bool fast{false};
        const bool reverse{true};
        ASSERT_EQ(target, executor->Query());
        ASSERT_EQ(fast, executor->FastQuery());
        ASSERT_EQ(reverse, executor->ReverseQuery());
    }

    TEST(ExecutorReverseTest, should_return_N_and_x_minus_1_given_status_is_reverse_command_is_BL_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        // when
        executor->Execute("BL");
        // then
        const Pose target{0, 0, 'S'};
        const bool fast{false};
        const bool reverse{true};
        ASSERT_EQ(target, executor->Query());
        ASSERT_EQ(reverse, executor->ReverseQuery());
        ASSERT_EQ(fast, executor->FastQuery());
    }

    TEST(ExecutorReverseTest, should_return_N_and_initpose_given_command_is_BL_and_facing_is_W)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
        // when
        executor->Execute("BLB");
        // then
        const Pose target{0, 0, 'N'};
        const bool fast{false};
        const bool reverse{false};
        ASSERT_EQ(target, executor->Query());
        ASSERT_EQ(reverse, executor->ReverseQuery());
        ASSERT_EQ(fast, executor->FastQuery());
    }

    TEST(ExecutorReverseTest, should_return_N_and_initpose_command_is_RBL_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        // when
        executor->Execute("RBL");
        // then
        const Pose target{0, 0, 'W'};
        const bool fast{false};
        const bool reverse{true};
        ASSERT_EQ(target, executor->Query());
        ASSERT_EQ(reverse, executor->ReverseQuery());
        ASSERT_EQ(fast, executor->FastQuery());
    }


}