#include "../include/rank.hpp"
#include "../include/usefull_types.hpp"
using namespace nxwheels;

struct A {
    constexpr const static inline size_t rank = 0;
};
struct B {
    constexpr const static inline size_t rank = 1;
};
int main() {
    // Test has_member_variable_rank_v.
    static_assert(has_member_variable_rank_v<A>);
    static_assert(has_member_variable_rank_v<B>);
    static_assert(!has_member_variable_rank_v<int>);

    // Test rank_v.
    static_assert(rank_v<int> == 0);
    static_assert(rank_v<int[]> == 1);
    static_assert(rank_v<const volatile int[]> == 1);
    {
        static_assert(rank_v<int[2][3]> == 2);
        using type = int[2];
        static_assert(rank_v<type[3]> == 2);
        static_assert(rank_v<type[]> == 2);
    }
    static_assert(rank_v<A[]> == 1);
    static_assert(rank_v<B[]> == 2);

    static_assert(rank_v<const volatile A[]> == 1);
    static_assert(rank_v<const volatile B[]> == 2);
}
