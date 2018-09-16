#include "../../../include/concepts/operations/is_convertible_v.hpp"
using namespace nxwheels;

struct C {};
struct A {
    A(const C&) {}
};
struct A1 {
    A1(const C&) noexcept {}
};

int main() {
    // Test is_implicitly_convertible_v.
    {
        static_assert(is_implicitly_convertible_v<int, int>);
        static_assert(is_implicitly_convertible_v<C, C>);

        static_assert(is_implicitly_convertible_v<char, int>);

        static_assert(is_implicitly_convertible_v<C, A>);
    }

    // Test is_nothrow_implicitly_convertible_v.
    {
        static_assert(is_nothrow_implicitly_convertible_v<C, A1>);
        static_assert(!is_nothrow_implicitly_convertible_v<C, A>);
    }
}
