// In this file we only test is_EqualityComparable_v.
#include "../../../include/concepts/operations/is_comparable_v.hpp"
using namespace nxwheels;

struct null {};

struct S1 {
    bool operator == (const S1&) { return true; }
    bool operator != (const S1&) { return true; }
};
struct S2 {
    bool operator == (const S2&) noexcept { return true; }
    bool operator != (const S2&) noexcept { return true; }
};

struct S3 {};
struct S4 {};

bool operator == (const S3&, const S4&) { return true; }

int main() {
    // Test is_EqualityCompareable_v.
    {

        static_assert(!is_EqualityCompareable_v<null, null>);

        static_assert(is_EqualityCompareable_v<int, int>);
        static_assert(is_EqualityCompareable_v<S1, S1>);
        static_assert(is_EqualityCompareable_v<S2, S2>);

    }

    // Test is_nothrow_EqualityCompareable_v.
    {

        static_assert(!is_nothrow_EqualityCompareable_v<null, null>);
        static_assert(!is_nothrow_EqualityCompareable_v<S1, S1>);

        static_assert(is_nothrow_EqualityCompareable_v<int, int>);
        static_assert(is_nothrow_EqualityCompareable_v<S2, S2>);

    }

    // Test is_raw_EqualityComparable_v.
    {
        static_assert(!is_raw_EqualityCompareable_v<const S4&, const S3&>);

        static_assert(is_raw_EqualityCompareable_v<const S3&, const S4&>);
    }
}
