#include "../../../../include/concepts/type_properties/operations/is_GreaterEqualComparable_v.hpp"
using namespace nxwheels;

struct NullOp {};
struct A {
    bool operator >= (const A&) { return false; }
};
struct B {
    bool operator >= (const B&) noexcept { return false; }
};

int main() {
    // Test is_GreaterEqualComparable_v.
    {

        static_assert(!is_GreaterEqualComparable_v<NullOp>);

        static_assert(is_GreaterEqualComparable_v<int>);
        static_assert(is_GreaterEqualComparable_v<A>);
        static_assert(is_GreaterEqualComparable_v<B>);

    }

    // Test is_nothrow_GreaterEqualComparable_v.
    {

        static_assert(!is_nothrow_GreaterEqualComparable_v<NullOp>);
        static_assert(!is_nothrow_GreaterEqualComparable_v<A>);

        static_assert(is_nothrow_GreaterEqualComparable_v<int>);
        static_assert(is_nothrow_GreaterEqualComparable_v<B>);

    }

}
