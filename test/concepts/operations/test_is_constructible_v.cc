#include <initializer_list>
#include "../../../include/concepts/operations/is_constructible_v.hpp"
using namespace nxwheels;

struct empty {};

struct A {
    A(int) {}
    A(const A&) = delete;
};
struct aggregate {
    int i;
    char c;
};

struct il_constructible {
    il_constructible(std::initializer_list<int>) {}
};
struct nothrow_il_constructible {
    nothrow_il_constructible(std::initializer_list<int>) noexcept {}
};

int main() {
    // Test is_direct_constructible_v.
    {
        // default
        static_assert(!is_direct_constructible_v<A>);

        static_assert(is_direct_constructible_v<empty>);
        static_assert(is_direct_constructible_v<aggregate>);
        // cp
        static_assert(!is_direct_constructible_v<A, A>);

        static_assert(is_direct_constructible_v<int, int>);
        static_assert(is_direct_constructible_v<empty, empty>);
        // User-defined
        static_assert(!is_direct_constructible_v<A, empty>);

        static_assert(is_direct_constructible_v<A, int>);

    }
    // Test is_nothrow_direct_constructiable_v.
    {
        static_assert(!is_nothrow_direct_constructible_v<A, int>);

        static_assert(is_nothrow_direct_constructible_v<empty>);
    }

    // Test is_list_constructible_v.
    {
        // default
        static_assert(!is_list_constructible_v<A>);

        static_assert(is_list_constructible_v<empty>);
        static_assert(is_list_constructible_v<aggregate>);
        // cp
        static_assert(!is_list_constructible_v<A, A>);

        static_assert(is_list_constructible_v<int, int>);
        static_assert(is_list_constructible_v<empty, empty>);
        // User-defined
        static_assert(!is_list_constructible_v<A, long long>);
        static_assert(!is_list_constructible_v<A, empty>);
        static_assert(!is_list_constructible_v<aggregate, long, char>);

        static_assert(is_list_constructible_v<A, int>);
        static_assert(is_list_constructible_v<aggregate, int>);
        static_assert(is_list_constructible_v<aggregate, int, char>);
        static_assert(is_list_constructible_v<aggregate, char, char>);

    }
    // Test is_nothrow_direct_constructiable_v.
    {
        static_assert(!is_nothrow_list_constructible_v<A, int>);

        static_assert(is_nothrow_list_constructible_v<empty>);
    }

    // Test is_initializer_list_constructiable_v.
    {
        static_assert(!is_initializer_list_constructible_v<il_constructible, empty>);

        static_assert(is_initializer_list_constructible_v<il_constructible, int, int, int>);
    }
    // Test is_nothrow_initializer_list_constructible_v.
    {
        static_assert(!is_nothrow_initializer_list_constructible_v<il_constructible, int, int, int>);

        static_assert(is_nothrow_initializer_list_constructible_v<nothrow_il_constructible, int, int, int>);
    }
}
