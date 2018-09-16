#include "../../../include/concepts/operations/is_subscriptable_v.hpp"
using namespace nxwheels;

struct NoOp {};

struct A {
    void operator [] (int) {}
};
struct C {
    void operator [] (int) noexcept {}
};

int main() {
    // Test is_subscriptable_v.
    {

        static_assert(!is_subscriptable_v<int, int>);
        static_assert(!is_subscriptable_v<NoOp, NoOp>);
        static_assert(!is_subscriptable_v<A, NoOp>);

        static_assert(is_subscriptable_v<int[], int>);
        static_assert(is_subscriptable_v<int*, int>);

        static_assert(is_subscriptable_v<A, int>);

    }

    // Test is_nothrow_subscriptable_v.
    {

        static_assert(!is_nothrow_subscriptable_v<int, int>);

        static_assert(is_nothrow_subscriptable_v<int[], int>);
        static_assert(is_nothrow_subscriptable_v<int*, int>);

        static_assert(is_nothrow_subscriptable_v<C, int>);

    }

}
