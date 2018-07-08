#include "../../../../src/concepts/type_properties/operations/is_EqualityComparable_v.hpp"
using namespace nxwheels::concept_check;

struct Boolean {
    bool b;
    constexpr operator bool () const noexcept { return b; }
};

struct S {};
struct S1 {
    bool operator == (const S1&) { return true; }
    bool operator != (const S1&) { return true; }
};
struct S2 {
    bool operator == (const S2&) noexcept { return true; }
    bool operator != (const S2&) noexcept { return true; }
};
struct S3 {
    Boolean operator == (const S3&) { return {true}; }
    Boolean operator != (const S3&) { return {true}; }
};

int main() {
    // Test is_EqualityComparable_v.
    {

        static_assert(!is_EqualityComparable_v<S>);

        static_assert(is_EqualityComparable_v<int>);
        static_assert(is_EqualityComparable_v<int*>);
        static_assert(is_EqualityComparable_v<S1>);
        static_assert(is_EqualityComparable_v<S2>);
        static_assert(is_EqualityComparable_v<S3>);

    }

    // Test is_nothrow_EqualityComparable_v.
    {

        static_assert(!is_nothrow_EqualityComparable_v<S>);
        static_assert(!is_nothrow_EqualityComparable_v<S1>);
        static_assert(!is_nothrow_EqualityComparable_v<S3>);

        static_assert(is_nothrow_EqualityComparable_v<int>);
        static_assert(is_nothrow_EqualityComparable_v<int*>);
        static_assert(is_nothrow_EqualityComparable_v<S2>);

    }

    // Test is_InEqualityComparable_v.
    {

        static_assert(!is_InEqualityComparable_v<S>);

        static_assert(is_InEqualityComparable_v<int>);
        static_assert(is_InEqualityComparable_v<int*>);
        static_assert(is_InEqualityComparable_v<S1>);
        static_assert(is_InEqualityComparable_v<S2>);
        static_assert(is_InEqualityComparable_v<S3>);

    }

    // Test is_nothrow_InEqualityComparable_v.
    {

        static_assert(!is_nothrow_InEqualityComparable_v<S>);
        static_assert(!is_nothrow_InEqualityComparable_v<S1>);
        static_assert(!is_nothrow_InEqualityComparable_v<S3>);

        static_assert(is_nothrow_InEqualityComparable_v<int>);
        static_assert(is_nothrow_InEqualityComparable_v<int*>);
        static_assert(is_nothrow_InEqualityComparable_v<S2>);

    }

}
