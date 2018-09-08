#include "../include/enable_if.hpp"
using namespace nxwheels;

template <class T> constexpr int F(T, enable_if_t<sizeof(T) == 1>* = nullptr)  noexcept { return 0; }
template <class T> constexpr int F(T, enable_if_t<sizeof(T) != 1>** = nullptr) noexcept { return 1; }

struct empty {};

int main() {
    static_assert(F(empty{}) == 0);
    static_assert(F(int{}) == 1);
}
