#include "../../../include/concepts/operations/is_arithmetic_v.hpp"
using namespace nxwheels;

struct null {};
struct A { A operator + () const          { return {}; } };
struct B { B operator + () const noexcept { return {}; } };
struct C { C operator + (const C&) const  { return {}; } };
struct D { D operator + (const D&) const noexcept { return {}; } };

int main() {
    //Test is_unary_plus_op_v.
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

    //Test has_addition_op_v.
    {

        static_assert(!is_additionable_v<null, null>);

        static_assert(is_additionable_v<int, int>);
        static_assert(is_additionable_v<C, C>);

    }

    //Test has_nothrow_addition_op_v.
    {

        static_assert(!is_nothrow_additionable_v<null, null>);
        static_assert(!is_nothrow_additionable_v<C, C>);

        static_assert(is_nothrow_additionable_v<int, int>);
        static_assert(is_nothrow_additionable_v<D, D>);

    }

}
