#include "../../../../include/concepts/type_properties/operations/is_GreaterThanComparable_v.hpp"
using namespace nxwheels;

struct NullOp {};
struct A {
    bool operator > (const A&) { return false; }
};
struct B {
    bool operator > (const B&) noexcept { return false; }
};

int main() {
    // Test is_GreaterThanComparable_v.
    {

        static_assert(!is_GreaterThanComparable_v<NullOp>);

        static_assert(is_GreaterThanComparable_v<int>);
        static_assert(is_GreaterThanComparable_v<A>);
        static_assert(is_GreaterThanComparable_v<B>);

    }

    // Test is_nothrow_GreaterThanComparable_v.
    {

        static_assert(!is_nothrow_GreaterThanComparable_v<NullOp>);
        static_assert(!is_nothrow_GreaterThanComparable_v<A>);

        static_assert(is_nothrow_GreaterThanComparable_v<int>);
        static_assert(is_nothrow_GreaterThanComparable_v<B>);

    }

}
