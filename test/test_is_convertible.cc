#include "../src/is_convertible.hpp"
using namespace nxwheels::concept_check;

struct C {};
struct A {
    A() = default;
    constexpr A(const C&) {}
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
    static_assert(is_implicitly_convertible_v<int, int>);
    static_assert(is_implicitly_convertible_v<char, int>);

    static_assert(is_implicitly_convertible_v<B, A>);
    static_assert(is_implicitly_convertible_v<const B, A>);

    static_assert(is_implicitly_convertible_v<C, A>);
    static_assert(is_implicitly_convertible_v<const C, A>);
    static_assert(is_implicitly_convertible_v<B, C>);
    static_assert(is_implicitly_convertible_v<const B, C>);

    static_assert(is_implicitly_convertible_v<D, D>);
}
