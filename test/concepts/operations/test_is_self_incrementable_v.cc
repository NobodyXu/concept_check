#include "../../../../include/concepts/type_properties/operations/is_self_incrementable_v.hpp"
using namespace nxwheels;

struct A {
    auto& operator ++ () { return *this; }
    auto operator ++ (int) { return *this; }
};
struct B {
    auto& operator ++ () noexcept { return *this; }
    auto operator ++ (int) noexcept { return *this; }
};

int main() {
    // Test is_pre_incrementable_v.
    {

        static_assert(!is_pre_incrementable_v<bool>);
        static_assert(!is_pre_incrementable_v<void () const volatile & noexcept>);

        static_assert(is_pre_incrementable_v<int&>);
        static_assert(is_pre_incrementable_v<int*&>);
        static_assert(is_pre_incrementable_v<A>);
        static_assert(is_pre_incrementable_v<B>);

    }

    // Test is_post_incrementable_v.
    {

        static_assert(!is_post_incrementable_v<bool>);
        static_assert(!is_post_incrementable_v<void () const volatile & noexcept>);

        static_assert(is_pre_incrementable_v<int&>);
        static_assert(is_pre_incrementable_v<int*&>);
        static_assert(is_pre_incrementable_v<A>);
        static_assert(is_pre_incrementable_v<B>);

    }

    // Test is_nothrow_pre_incrementable_v.
    {

        static_assert(!is_nothrow_pre_incrementable_v<bool>);
        static_assert(!is_nothrow_pre_incrementable_v<void () const volatile & noexcept>);
        static_assert(!is_nothrow_pre_incrementable_v<A>);

        static_assert(is_nothrow_pre_incrementable_v<int&>);
        static_assert(is_nothrow_pre_incrementable_v<int*&>);
        static_assert(is_nothrow_pre_incrementable_v<B>);

    }

    // Test is_nothrow_post_incrementable_v.
    {

        static_assert(!is_nothrow_post_incrementable_v<bool>);
        static_assert(!is_nothrow_post_incrementable_v<void () const volatile & noexcept>);
        static_assert(!is_nothrow_pre_incrementable_v<A>);

        static_assert(is_nothrow_pre_incrementable_v<int&>);
        static_assert(is_nothrow_pre_incrementable_v<int*&>);
        static_assert(is_nothrow_pre_incrementable_v<B>);

    }

}
