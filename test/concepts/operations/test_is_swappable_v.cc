#include <utility>
using std::swap;

#include "../../../include/concepts/operations/is_swappable_v.hpp"
using namespace nxwheels;

#include "../../four_types.hpp"
struct S2 {};

void swap(S&&, S&&) {}
void swap(S2&&, S2&&) noexcept {}

int main() {
    // Test is_swappable_v.
    {
        static_assert(!is_swappable_v<void>);
        static_assert(!is_swappable_v<void () const volatile && noexcept>);

        static_assert(is_swappable_v<int&>);
        static_assert(is_swappable_v<int (&)[22]>);
        static_assert(is_swappable_v<int*&>);
        static_assert(is_swappable_v<void (*&)() noexcept>);

        static_assert(is_swappable_v<S&>);
        static_assert(is_swappable_v<U&>);
        static_assert(is_swappable_v<unscoped_e&>);
        static_assert(is_swappable_v<scoped_e&>);

        static_assert(is_swappable_v<S>);
        static_assert(is_swappable_v<S2>);
    }

    // Test is_nothrow_swappable_v.
    {
        static_assert(!is_nothrow_swappable_v<void>);
        static_assert(!is_nothrow_swappable_v<void () const volatile && noexcept>);
        static_assert(!is_nothrow_swappable_v<S>);

        static_assert(is_nothrow_swappable_v<int&>);
        static_assert(is_nothrow_swappable_v<int (&)[22]>);
        static_assert(is_nothrow_swappable_v<int*&>);
        static_assert(is_nothrow_swappable_v<void (*&)() noexcept>);

        static_assert(is_nothrow_swappable_v<S&>);
        static_assert(is_nothrow_swappable_v<U&>);
        static_assert(is_nothrow_swappable_v<unscoped_e&>);
        static_assert(is_nothrow_swappable_v<scoped_e&>);

        static_assert(is_nothrow_swappable_v<S2>);
    }

}
