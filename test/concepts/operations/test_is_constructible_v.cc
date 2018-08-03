#include <initializer_list>
#include "../../../include/concepts/operations/is_constructible_v.hpp"
using namespace nxwheels;

struct A {
    A(int) {}
    A(const A&) = default;
};
struct B {
    B() = default;
    B(int) {}
    ~B() = delete;
};
struct C {
    C(int) noexcept {}
};
struct Aggregate {
    int i;
    char c;
};
struct wrapper_over_aggregate {
    Aggregate a;
    wrapper_over_aggregate(int, char);
};
struct initializer_list_constructible {
    initializer_list_constructible(std::initializer_list<int> il) {}
};
struct nothrow_initializer_list_constructible {
    nothrow_initializer_list_constructible(std::initializer_list<int> il) noexcept {}
};

int main() {
    // Test is_direct_constructible_v.
    // 0 argument
    static_assert(!is_direct_constructible_v<A>);
    static_assert(is_direct_constructible_v<B>);
    static_assert(is_direct_constructible_v<Aggregate>);
    // 1 argument
    static_assert(is_direct_constructible_v<A, int>);
    static_assert(is_direct_constructible_v<B, int>);
    // cp
    static_assert(is_direct_constructible_v<int, int>);
    // 2 arguments
    static_assert(is_direct_constructible_v<wrapper_over_aggregate, int, char>);
    // Aggregate
    static_assert(!is_direct_constructible_v<Aggregate, int, char>);
    // std::initializer_list
    static_assert(is_direct_constructible_v<initializer_list_constructible, std::initializer_list<int>>);

    // Test is_nothrow_direct_constructiable_v.
    static_assert(!is_nothrow_direct_constructible_v<A, int>);
    static_assert(!is_nothrow_direct_constructible_v<B, int>);
    static_assert(is_nothrow_direct_constructible_v<int, int>);
    static_assert(is_nothrow_direct_constructible_v<C, int>);

    // Test is_list_constructible_v.
    // 0 argument
    static_assert(!is_list_constructible_v<A>);
    static_assert(is_list_constructible_v<B>);
    static_assert(is_list_constructible_v<Aggregate>);
    // 1 argument
    static_assert(is_list_constructible_v<A, int>);
    static_assert(is_list_constructible_v<B, int>);
    static_assert(is_list_constructible_v<Aggregate, int>);
    // cp
    static_assert(is_list_constructible_v<int, int>);
    static_assert(is_list_constructible_v<Aggregate, Aggregate>);
    static_assert(is_list_constructible_v<A, A>);
    // 2 argument
    static_assert(is_list_constructible_v<Aggregate, int, char>);
    static_assert(is_list_constructible_v<wrapper_over_aggregate, int, char>);
    // initialier_list
    static_assert(is_list_constructible_v<initializer_list_constructible, int, int, int>);
    static_assert(is_list_constructible_v<initializer_list_constructible, int, int, char>);

    // Test is_nothrow_list_constructiable_v.
    static_assert(is_nothrow_list_constructible_v<Aggregate>);
    static_assert(is_nothrow_list_constructible_v<Aggregate, int>);
    static_assert(is_nothrow_list_constructible_v<Aggregate, int, char>);

    static_assert(!is_nothrow_list_constructible_v<A, int>);
    static_assert(!is_nothrow_list_constructible_v<B, int>);
    static_assert(is_nothrow_list_constructible_v<C, int>);
    // cp
    static_assert(is_nothrow_list_constructible_v<int, int>);
    static_assert(is_nothrow_list_constructible_v<Aggregate, Aggregate>);
    static_assert(is_nothrow_list_constructible_v<A, A>);
    // initializer_list
    static_assert(!is_nothrow_list_constructible_v<initializer_list_constructible, int, int, int, char>);
    static_assert(is_nothrow_list_constructible_v<nothrow_initializer_list_constructible, int, int, int, char>);

    // Test is_initializer_list_constructible_v.
    static_assert(!is_initializer_list_constructible_v<int, int>);

    static_assert(is_initializer_list_constructible_v<std::initializer_list<int>>);
    static_assert(is_initializer_list_constructible_v<std::initializer_list<int>, int, char>);
    static_assert(is_initializer_list_constructible_v<initializer_list_constructible>);
    static_assert(is_initializer_list_constructible_v<initializer_list_constructible, int, char>);

    // Test is_nothrow_initializer_list_constructible_v.
    static_assert(!is_nothrow_initializer_list_constructible_v<int, int>);

    static_assert(is_nothrow_initializer_list_constructible_v<nothrow_initializer_list_constructible>);
    static_assert(is_nothrow_initializer_list_constructible_v<nothrow_initializer_list_constructible, int, char>);
}
