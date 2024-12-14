#include <gtest/gtest.h>
#include<memory>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas {

    TEST(ExecutorBusTest, should_return_y_plus_1_given_command_is_FFM_and_facing_is_N) {
        // Arrange（准备）：创建一个 Executor 对象，初始化 Pose 为 {0, 0, 'N'}
        std::unique_ptr<Executor> executor(Executor::NewExecutor());

        // Act（执行）：无需额外操作，仅调用 Query
        executor->ExecuteBus("FFM");
        // Assert（验证）：检查返回的 Pose 是否与预期相等
        const Pose target({0, 1, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorBusTest, should_return_N_and_x_plus_1_given_status_is_fast_command_is_FL_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        // when
        executor->ExecuteBus("FL");
        // then
        const Pose target{2, 0, 'N'};
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorBusTest, should_return_S_and_x_plus_1_given_status_is_fast_given_command_is_FR_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        // when
        executor->ExecuteBus("FR");
        // then
        const Pose target{2, 0, 'S'};
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorBusTest, should_return_x_plus_4_given_status_is_fast_command_is_FM_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        // when
        executor->ExecuteBus("FM");
        // then
        const Pose target{2, 0, 'E'};
        ASSERT_EQ(target, executor->Query());
    }

}