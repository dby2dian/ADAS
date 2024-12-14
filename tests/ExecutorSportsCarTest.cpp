#include <gtest/gtest.h>
#include<memory>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas {

    TEST(ExecutorSportsCarTest, should_return_y_plus_2_given_command_is_FFM_and_facing_is_N) {
        // Arrange（准备）：创建一个 Executor 对象，初始化 Pose 为 {0, 0, 'N'}
        std::unique_ptr<Executor> executor(Executor::NewExecutor());

        // Act（执行）：无需额外操作，仅调用 Query
        executor->ExecuteSportsCar("FFM");
        // Assert（验证）：检查返回的 Pose 是否与预期相等
        const Pose target({0, 2, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorSportsCarTest, should_return_N_and_x_plus_1_y_plus_1_given_status_is_fast_command_is_FL_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        // when
        executor->ExecuteSportsCar("FL");
        // then
        const Pose target{1, 1, 'N'};
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorSportsCarTest, should_return_S_and_x_plus_1_y_minus_1_given_status_is_fast_given_command_is_FR_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        // when
        executor->ExecuteSportsCar("FR");
        // then
        const Pose target{1, -1, 'S'};
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorSportsCarTest, should_return_x_plus_4_given_status_is_fast_command_is_FM_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        // when
        executor->ExecuteSportsCar("FM");
        // then
        const Pose target{4, 0, 'E'};
        ASSERT_EQ(target, executor->Query());
    }

}