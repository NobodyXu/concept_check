#include "../../../../src/concepts/type_properties/operations/is_convertible_v.hpp"
using namespace nxwheels::concept_check;

struct C {};
struct A {
    A() = default;
    A(const A&) = default;
    A(A&&) = default;
    constexpr A(const C&) {}
};
struct A1 {
    A1() = default;
    constexpr explicit A1(const C&) {}
};
struct B {
    constexpr operator A ()       noexcept { return {}; }
    constexpr operator C () const noexcept { return {}; }
};
struct D {
    D() = default;
    D(const D&) = delete;
    D(D&&) = delete;
};

int main() {
    // Test is_implicitly_convertible_v.
    {
        assert_implicitly_convertible<int, int>();
        assert_implicitly_convertible<char, int>();

        assert_implicitly_convertible<B, A>();
        assert_not_implicitly_convertible<const B, A>();

        assert_implicitly_convertible<C, A>();
        assert_implicitly_convertible<const C, A>();
        assert_implicitly_convertible<B, C>();
        assert_implicitly_convertible<const B, C>();

        assert_implicitly_convertible<D, D>();
        assert_implicitly_convertible<void, void>();

        assert_not_implicitly_convertible<void, int>();
        assert_not_implicitly_convertible<int, A>();
        assert_not_implicitly_convertible<C, A1>();
    }

    // Test is_nothrow_implicitly_convertible_v.
    {
        assert_nothrow_implicitly_convertible<B, A>();
        assert_not_nothrow_implicitly_convertible<C, A>();
    }
}
