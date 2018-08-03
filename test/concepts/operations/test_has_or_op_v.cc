#include "../../../include/concepts/operations/has_or_op_v.hpp"
using namespace nxwheels;

struct O {};
struct A {
    bool operator || (const A&) const noexcept { return true; }
};
struct B {
    bool operator || (const B&) noexcept { return true; }
};
struct C {
    bool operator || (const C&) const { return true; }
};
struct D {
    bool operator || (const D&) { return true; }
};

int main() {
    // Test has_not_op_v.
    {

        static_assert(!has_or_op_v<O, O>);
        static_assert(!has_or_op_v<const B&, const B&>);

        static_assert(has_or_op_v<int, int>);
        static_assert(has_or_op_v<const A&, const A&>);
        static_assert(has_or_op_v<B, const B&>);

    }

    // Test has_nothrow_not_op_v.
    {

        static_assert(!has_nothrow_or_op_v<O, O>);
        static_assert(!has_nothrow_or_op_v<const B&, const B&>);
        static_assert(!has_nothrow_or_op_v<const C&, const C&>);

        static_assert(has_nothrow_or_op_v<int, int>);
        static_assert(has_nothrow_or_op_v<const A&, const A&>);
        static_assert(has_nothrow_or_op_v<B, const B&>);

    }
}
