#include <utility>
using std::swap;

#include "../../../../src/concepts/type_properties/operations/is_swappable_v.hpp"
using namespace nxwheels::concept_check;

#include "../../four_types.hpp"
struct S2 {};

void swap(S&&, S&&) {}
void swap(S2&&, S2&&) noexcept {}
void swap(S&&, U&&) {}
void swap(S&&, U&) noexcept {}

int main() {
    // Test is_swappable_v.
    {
        static_assert(!is_swappable_v<void>);
        static_assert(!is_swappable_v<void () const volatile && noexcept>);

        static_assert(is_swappable_v<int&>);
        static_assert(is_swappable_v<int (&)[]>);
        static_assert(is_swappable_v<int*&>);
        static_assert(is_swappable_v<void (&)() noexcept>);
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
        static_assert(is_nothrow_swappable_v<int (&)[]>);
        static_assert(is_nothrow_swappable_v<int*&>);
        static_assert(is_nothrow_swappable_v<void (&)() noexcept>);
        static_assert(is_nothrow_swappable_v<void (*&)() noexcept>);

        static_assert(is_nothrow_swappable_v<S&>);
        static_assert(is_nothrow_swappable_v<U&>);
        static_assert(is_nothrow_swappable_v<unscoped_e&>);
        static_assert(is_nothrow_swappable_v<scoped_e&>);

        static_assert(is_nothrow_swappable_v<S2>);
    }

    // Test is_swappable_with_v.
    {
        template <class T> constexpr const static inline Is_swappable_v = is_swappable_with_v<T, T>;
        static_assert(!Is_swappable_v<void>);
        static_assert(!Is_swappable_v<void () const volatile && noexcept>);

        static_assert(Is_swappable_v<int&>);
        static_assert(Is_swappable_v<int (&)[]>);
        static_assert(Is_swappable_v<int*&>);
        static_assert(Is_swappable_v<void (&)() noexcept>);
        static_assert(Is_swappable_v<void (*&)() noexcept>);

        static_assert(Is_swappable_v<S&>);
        static_assert(Is_swappable_v<U&>);
        static_assert(Is_swappable_v<unscoped_e&>);
        static_assert(Is_swappable_v<scoped_e&>);

        static_assert(Is_swappable_v<S>);
        static_assert(Is_swappable_v<S2>);

        static_assert(is_swappable_with_v<S, U>);
        static_assert(is_swappable_with_v<S, U&>);
    }

    // Test is_nothrow_swappable_with_v.
    {
        template <class T> constexpr const static inline bool Is_nothrow_swappable_v = is_nothrow_swappable_with_v<T, T>;

        static_assert(!Is_nothrow_swappable_v<void>);
        static_assert(!Is_nothrow_swappable_v<void () const volatile && noexcept>);
        static_assert(!Is_nothrow_swappable_v<S>);
        static_assert(!is_nothrow_swappable_with_v<S, U>);

        static_assert(Is_nothrow_swappable_v<int&>);
        static_assert(Is_nothrow_swappable_v<int (&)[]>);
        static_assert(Is_nothrow_swappable_v<int*&>);
        static_assert(Is_nothrow_swappable_v<void (&)() noexcept>);
        static_assert(Is_nothrow_swappable_v<void (*&)() noexcept>);

        static_assert(Is_nothrow_swappable_v<S&>);
        static_assert(Is_nothrow_swappable_v<U&>);
        static_assert(Is_nothrow_swappable_v<unscoped_e&>);
        static_assert(Is_nothrow_swappable_v<scoped_e&>);

        static_assert(Is_nothrow_swappable_v<S2>);
        static_assert(is_nothrow_swappable_with_v<S, U&>);
    }
}
