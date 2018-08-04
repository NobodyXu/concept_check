#include "../../../include/concepts/operations/has_arithmetic_op_v.hpp"
using namespace nxwheels;

struct null {};
struct A { A operator + () const          { return {}; } };
struct B { B operator + () const noexcept { return {}; } };
struct C { C operator + (const C&) const  { return {}; } };
struct D { D operator + (const D&) const noexcept { return {}; } };

int main() {
    //Test has_unary_plus_op_v.
    {

        static_assert(!has_unary_plus_op_v<null>);

        static_assert(has_unary_plus_op_v<int>);
        static_assert(has_unary_plus_op_v<A>);

    }

    //Test has_nothrow_unary_plus_op_v.
    {

        static_assert(!has_nothrow_unary_plus_op_v<null>);
        static_assert(!has_nothrow_unary_plus_op_v<A>);

        static_assert(has_nothrow_unary_plus_op_v<int>);
        static_assert(has_nothrow_unary_plus_op_v<B>);

    }

    //Test has_addition_op_v.
    {

        static_assert(!has_addition_op_v<null, null>);

        static_assert(has_addition_op_v<int, int>);
        static_assert(has_addition_op_v<C, C>);

    }

    //Test has_nothrow_addition_op_v.
    {

        static_assert(!has_nothrow_addition_op_v<null, null>);
        static_assert(!has_nothrow_addition_op_v<C, C>);

        static_assert(has_nothrow_addition_op_v<int, int>);
        static_assert(has_nothrow_addition_op_v<D, D>);

    }

}
