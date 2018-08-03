#include "../../../include/concepts/operations/is_LessEqualComparable_v.hpp"
using namespace nxwheels;

struct NullOp {};
struct A {
    bool operator <= (const A&) { return false; }
};
struct B {
    bool operator <= (const B&) noexcept { return false; }
};

int main() {
    // Test is_LessEqualComparable_v.
    {

        static_assert(!is_LessEqualComparable_v<NullOp>);

        static_assert(is_LessEqualComparable_v<int>);
        static_assert(is_LessEqualComparable_v<A>);
        static_assert(is_LessEqualComparable_v<B>);

    }

    // Test is_nothrow_LessEqualComparable_v.
    {

        static_assert(!is_nothrow_LessEqualComparable_v<NullOp>);
        static_assert(!is_nothrow_LessEqualComparable_v<A>);

        static_assert(is_nothrow_LessEqualComparable_v<int>);
        static_assert(is_nothrow_LessEqualComparable_v<B>);

    }

}
