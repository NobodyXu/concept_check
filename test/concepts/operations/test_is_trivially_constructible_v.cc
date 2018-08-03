#include <initializer_list>
#include "../../../include/concepts/operations/is_trivially_constructible.hpp"
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
struct nontrivially_default_constructible_aggregate {
    int i = 2222;
    char c = 'd';
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

enum       unscoped_enum_int: int {};
enum class scoped_enum_int:   int {};

int main() {
    // Test is_trivially_constructible_v.
    static_assert(!is_trivially_default_constructible_v<A>);

    static_assert(is_trivially_default_constructible_v<int>);
    static_assert(is_trivially_default_constructible_v<Aggregate>);

    // Test is_trivially_copy_constructible_v.
    static_assert(is_trivially_copy_constructible_v<int>);
    static_assert(is_trivially_copy_constructible_v<A>);
    static_assert(is_trivially_copy_constructible_v<Aggregate>);

    // Test is_trivially_direct_constructible_v.
    static_assert(is_trivially_direct_constructible_v<int>);
    static_assert(is_trivially_direct_constructible_v<int, int>);
    static_assert(is_trivially_direct_constructible_v<A, A>);
    static_assert(is_trivially_direct_constructible_v<A, const A&>);
    static_assert(is_trivially_direct_constructible_v<A, A&&>);
    static_assert(is_trivially_direct_constructible_v<B>);

    static_assert(is_trivially_direct_constructible_v<Aggregate>);
    static_assert(is_trivially_direct_constructible_v<Aggregate, Aggregate>);
    static_assert(is_trivially_direct_constructible_v<Aggregate, const Aggregate&>);
    static_assert(is_trivially_direct_constructible_v<Aggregate, Aggregate&&>);
    static_assert(!is_trivially_direct_constructible_v<nontrivially_default_constructible_aggregate>);

    static_assert(is_trivially_direct_constructible_v<unscoped_enum_int>);
    static_assert(is_trivially_direct_constructible_v<scoped_enum_int>);

    static_assert(!is_trivially_direct_constructible_v<std::initializer_list<int>>);
    static_assert(is_trivially_direct_constructible_v<std::initializer_list<int>, std::initializer_list<int>>);
    static_assert(is_trivially_direct_constructible_v<std::initializer_list<int>, const std::initializer_list<int>&>);
    static_assert(is_trivially_direct_constructible_v<std::initializer_list<int>, std::initializer_list<int>&&>);
    static_assert(!is_trivially_direct_constructible_v<std::initializer_list<int>, int>);
}
