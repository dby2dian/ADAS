#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas {

// 测试用例 1：验证正常情况下执行 TR (TurnRight) 命令的行为
TEST(ExecutorTurnRoundTest, should_normal_tr_build_left_forward_left)
{
    // given: 创建一个 Executor 实例，初始状态为 {0, 0, 'E'}
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when: 执行 "TR" 命令
    executor->Execute("TR");

    // then: 验证执行后目标位姿应为 {0, 1, 'W'}
    const Pose target{0, 1, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// 测试用例 2：验证快速模式下执行 FTR (Forward Turn Right) 命令的行为
TEST(ExecutorTurnRoundTest, should_fast_tr_build_forward_left_forward_left)
{
    // given: 创建一个 Executor 实例，初始状态为 {0, 0, 'E'}
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when: 执行 "FTR" 命令
    executor->Execute("FTR");

    // then: 验证执行后目标位姿应为 {1, 1, 'W'}
    const Pose target{1, 1, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// 测试用例 3：验证在反向状态 (B) 下，执行 TR 命令时命令被忽略
TEST(ExecutorTurnRoundTest, in_the_B_state_the_reverse_command_will_be_ignored)
{
    // given: 创建一个 Executor 实例，初始状态为 {0, 0, 'E'}
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when: 执行 "BTR" 命令
    executor->Execute("BTR");

    // then: 验证执行后目标位姿应仍为 {0, 0, 'E'}，即命令被忽略
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

}  // namespace adas
