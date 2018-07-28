#include "../../../../include/concepts/type_properties/operations/has_not_op_v.hpp"
using namespace nxwheels;

struct O {};
struct A {
    bool operator ! () const noexcept { return true; }
};
struct B {
    bool operator ! () noexcept { return true; }
};
struct C {
    bool operator ! () const { return true; }
};
struct D {
    bool operator ! () { return true; }
};

int main() {
    // Test has_not_op_v.
    {

        static_assert(!has_not_op_v<O>);
        static_assert(!has_not_op_v<const B&>);

        static_assert(has_not_op_v<int>);
        static_assert(has_not_op_v<const A&>);
        static_assert(has_not_op_v<B>);

    }

    // Test has_nothrow_not_op_v.
    {

        static_assert(!has_nothrow_not_op_v<O>);
        static_assert(!has_nothrow_not_op_v<const B&>);
        static_assert(!has_nothrow_not_op_v<const C&>);

        static_assert(has_nothrow_not_op_v<int>);
        static_assert(has_nothrow_not_op_v<const A&>);
        static_assert(has_nothrow_not_op_v<B>);

    }
}
