// In this file we only test is_EqualityComparable_v.
#include "../../../include/concepts/operations/is_comparable_v.hpp"
using namespace nxwheels;

struct null {};
struct Boolean {
    bool b;
    constexpr operator bool () const noexcept { return b; }
};

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
    // Test is_EqualityCompareable_v.
    {

        static_assert(!is_EqualityCompareable_v<null, null>);

        static_assert(is_EqualityCompareable_v<int, int>);
        static_assert(is_EqualityCompareable_v<int*, int*>);
        static_assert(is_EqualityCompareable_v<S1, S1>);
        static_assert(is_EqualityCompareable_v<S2, S2>);
        static_assert(is_EqualityCompareable_v<S3, S3>);

    }

    // Test is_nothrow_EqualityCompareable_v.
    {

        static_assert(!is_nothrow_EqualityCompareable_v<null, null>);
        static_assert(!is_nothrow_EqualityCompareable_v<S1, S1>);
        static_assert(!is_nothrow_EqualityCompareable_v<S3, S3>);

        static_assert(is_nothrow_EqualityCompareable_v<int, int>);
        static_assert(is_nothrow_EqualityCompareable_v<int*, int*>);
        static_assert(is_nothrow_EqualityCompareable_v<S2, S2>);

    }

    // Test is_InEqualityCompareable_v.
    {

        static_assert(!is_InEqualityCompareable_v<null, null>);

        static_assert(is_InEqualityCompareable_v<int, int>);
        static_assert(is_InEqualityCompareable_v<int*, int*>);
        static_assert(is_InEqualityCompareable_v<S1, S1>);
        static_assert(is_InEqualityCompareable_v<S2, S2>);
        static_assert(is_InEqualityCompareable_v<S3, S3>);

    }

    // Test is_nothrow_InEqualityCompareable_v.
    {

        static_assert(!is_nothrow_InEqualityCompareable_v<null, null>);
        static_assert(!is_nothrow_InEqualityCompareable_v<S1, S1>);
        static_assert(!is_nothrow_InEqualityCompareable_v<S3, S3>);

        static_assert(is_nothrow_InEqualityCompareable_v<int, int>);
        static_assert(is_nothrow_InEqualityCompareable_v<int*, int*>);
        static_assert(is_nothrow_InEqualityCompareable_v<S2, S2>);

    }
}
