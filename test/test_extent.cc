#include "../include/extent.hpp"
using namespace nxwheels;

struct A {
    constexpr const static inline size_t extent = 1;
};
int main() {
    // Test has_member_variable_extent_v.
    static_assert(!has_member_variable_extent_v<int>);
    static_assert(has_member_variable_extent_v<A>);

    // Test extent_v.
    static_assert(extent_v<int> == 0);
    static_assert(extent_v<int[]> == 0);
    static_assert(extent_v<const volatile int[]> == 0);

    static_assert(extent_v<const volatile int[1]> == 1);

    static_assert(extent_v<A> == 1);
    static_assert(extent_v<const volatile A> == 1);
}
