#include "../../../include/concepts/operations/is_arithmetic_v.hpp"
using namespace nxwheels;

struct null {};
struct A { A operator + () const          { return {}; } };
struct B { B operator + () const noexcept { return {}; } };
struct C { C operator + (const C&) const  { return {}; } };
struct D { D operator + (const D&) const noexcept { return {}; } };

struct E { E& operator += (const E&) noexcept { return *this; } };
struct F { F& operator += (const E&)          { return *this; } };

// Test additionable_t.
template <class T>
void Func(additionable_t<T, T> &&) {}

int main() {
    //Test is_unary_plusable_v.
    {

        static_assert(!is_unary_plusable_v<null>);

        static_assert(is_unary_plusable_v<int>);
        static_assert(is_unary_plusable_v<A>);

    }

    //Test is_nothrow_unary_plusable_v.
    {

        static_assert(!is_nothrow_unary_plusable_v<null>);
        static_assert(!is_nothrow_unary_plusable_v<A>);

        static_assert(is_nothrow_unary_plusable_v<int>);
        static_assert(is_nothrow_unary_plusable_v<B>);

    }

    //Test is_additionable_v.
    {

        static_assert(!is_additionable_v<null, null>);

        static_assert(is_additionable_v<int, int>);
        static_assert(is_additionable_v<C, C>);

    }

    //Test is_nothrow_additionable_v.
    {

        static_assert(!is_nothrow_additionable_v<null, null>);
        static_assert(!is_nothrow_additionable_v<C, C>);

        static_assert(is_nothrow_additionable_v<int, int>);
        static_assert(is_nothrow_additionable_v<D, D>);

    }

    //Test is_addition_assignmentable_v.
    {

        static_assert(!is_addition_assignmentable_v<null, null>);

        static_assert(is_addition_assignmentable_v<int&, int&>);
        static_assert(is_addition_assignmentable_v<E&, E>);

    }

    //Test is_nothrow_addition_assignmentable_v.
    {

        static_assert(!is_nothrow_addition_assignmentable_v<null, null>);
        static_assert(!is_nothrow_addition_assignmentable_v<C, C>);
        static_assert(!is_nothrow_addition_assignmentable_v<F, F>);

        static_assert(is_nothrow_addition_assignmentable_v<int&, int>);
        static_assert(is_nothrow_addition_assignmentable_v<E, E>);

    }

    // Test additionable_t.
    {

        //Func(F{});
        Func(int{});

    }
}
