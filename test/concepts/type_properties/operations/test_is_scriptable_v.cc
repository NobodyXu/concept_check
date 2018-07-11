#include "../../../../include/concepts/type_properties/operations/is_subscriptable_v.hpp"
using namespace nxwheels;

struct NoOp {};
struct Tag {};
struct A {
    void operator [] (int) {}
};
struct B {
    void operator [] (Tag) {}
};
struct C {
    void operator [] (int) noexcept {}
};
struct D {
    void operator [] (Tag) noexcept {}
};

int main() {
    // Test is_subscriptable_v.
    {

        static_assert(!is_subscriptable_v<int, int>);

        static_assert(is_subscriptable_v<int[2333], int>);
        static_assert(is_subscriptable_v<int[], int>);
        static_assert(is_subscriptable_v<int*, int>);

        static_assert(is_subscriptable_v<A, int>);
        static_assert(is_subscriptable_v<B, Tag>);
        static_assert(is_subscriptable_v<C, int>);
        static_assert(is_subscriptable_v<D, Tag>);

    }

    // Test is_nothrow_subscriptable_v.
    {

        static_assert(!is_nothrow_subscriptable_v<int, int>);
        static_assert(!is_nothrow_subscriptable_v<A, int>);
        static_assert(!is_nothrow_subscriptable_v<B, Tag>);

        static_assert(is_nothrow_subscriptable_v<int[2333], int>);
        static_assert(is_nothrow_subscriptable_v<int[], int>);
        static_assert(is_nothrow_subscriptable_v<int*, int>);

        static_assert(is_nothrow_subscriptable_v<C, int>);
        static_assert(is_nothrow_subscriptable_v<D, Tag>);

    }

}
