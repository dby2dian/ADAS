#pragma once

namespace adas {

template <typename T>
class Singleton final {
public:
    static T& Instance(void) noexcept {
        static T instance;  // 静态局部变量，确保单例只创建一次
        return instance;
    }

    Singleton(const Singleton&) noexcept = delete;

    Singleton& operator=(const Singleton&) noexcept = delete;

private:

    Singleton(void) noexcept = default;

    ~Singleton(void) noexcept = default;
};

}  // namespace adas
