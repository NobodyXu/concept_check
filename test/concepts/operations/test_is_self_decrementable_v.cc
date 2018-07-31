#include "../../../../include/concepts/type_properties/operations/is_self_decrementable_v.hpp"
using namespace nxwheels;

struct A {
    A& operator -- ();
    A& operator -- (int);
};
struct B {
    B& operator -- () noexcept;
    B& operator -- (int) noexcept;
};

int main() {
    // Test is_pre_decrementable_v.
    {

        static_assert(!is_pre_decrementable_v<bool&>);

        static_assert(is_pre_decrementable_v<char&>);
        static_assert(is_pre_decrementable_v<int&>);
        static_assert(is_pre_decrementable_v<A>);
        static_assert(is_pre_decrementable_v<B>);

    }

    // Test is_nothrow_pre_decrementable_v.
    {

        static_assert(!is_nothrow_pre_decrementable_v<bool&>);
        static_assert(!is_nothrow_pre_decrementable_v<A>);

        static_assert(is_nothrow_pre_decrementable_v<char&>);
        static_assert(is_nothrow_pre_decrementable_v<int&>);
        static_assert(is_nothrow_pre_decrementable_v<B>);

    }

    // Test is_post_decrementable_v.
    {

        static_assert(!is_post_decrementable_v<bool&>);

        static_assert(is_post_decrementable_v<char&>);
        static_assert(is_post_decrementable_v<int&>);
        static_assert(is_post_decrementable_v<A>);
        static_assert(is_post_decrementable_v<B>);

    }

    // Test is_nothrow_post_decrementable_v.
    {

        static_assert(!is_nothrow_post_decrementable_v<bool&>);
        static_assert(!is_nothrow_post_decrementable_v<A>);

        static_assert(is_nothrow_post_decrementable_v<char&>);
        static_assert(is_nothrow_post_decrementable_v<int&>);
        static_assert(is_nothrow_post_decrementable_v<B>);

    }

}
