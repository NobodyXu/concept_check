#include "../../../include/concepts/operations/is_LessThanComparable_v.hpp"
using namespace nxwheels;

struct Boolean {
    bool b;
    constexpr operator bool () const noexcept { return b; }
};

struct S {};
struct S1 {
    bool operator < (const S1&) { return true; }
};
struct S2 {
    bool operator < (const S2&) noexcept { return true; }
};
struct S3 {
    Boolean operator < (const S3&) { return {true}; }
};

int main() {
    // Test is_LessThanComparable_v.
    {

        static_assert(!is_LessThanComparable_v<S>);

        static_assert(is_LessThanComparable_v<int>);
        static_assert(is_LessThanComparable_v<int*>);
        static_assert(is_LessThanComparable_v<S1>);
        static_assert(is_LessThanComparable_v<S2>);
        static_assert(is_LessThanComparable_v<S3>);

    }

    // Test is_nothrow_LessThanComparable_v.
    {

        static_assert(!is_nothrow_LessThanComparable_v<S>);
        static_assert(!is_nothrow_LessThanComparable_v<S1>);
        static_assert(!is_nothrow_LessThanComparable_v<S3>);

        static_assert(is_nothrow_LessThanComparable_v<int>);
        static_assert(is_nothrow_LessThanComparable_v<int*>);
        static_assert(is_nothrow_LessThanComparable_v<S2>);

    }

    // Test is_LessThanComparable_v.
    {

        static_assert(!is_LessThanComparable_v<S>);

        static_assert(is_LessThanComparable_v<int>);
        static_assert(is_LessThanComparable_v<int*>);
        static_assert(is_LessThanComparable_v<S1>);
        static_assert(is_LessThanComparable_v<S2>);
        static_assert(is_LessThanComparable_v<S3>);

    }

    // Test is_nothrow_LessThanComparable_v.
    {

        static_assert(!is_nothrow_LessThanComparable_v<S>);
        static_assert(!is_nothrow_LessThanComparable_v<S1>);
        static_assert(!is_nothrow_LessThanComparable_v<S3>);

        static_assert(is_nothrow_LessThanComparable_v<int>);
        static_assert(is_nothrow_LessThanComparable_v<int*>);
        static_assert(is_nothrow_LessThanComparable_v<S2>);

    }

}
