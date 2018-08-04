#include "../../../include/concepts/operations/has_logical_v.hpp"
using namespace nxwheels;

struct O {};
#define DEF_TYPE_TO_CHECK(NAME, OP)                                      \
namespace NAME {                                                         \
struct A { bool operator OP (const A&) const noexcept { return true; } };\
struct B { bool operator OP (const B&) noexcept       { return true; } };\
struct C { bool operator OP (const C&) const          { return true; } };\
struct D { bool operator OP (const D&)                { return true; } };\
} /* NAME */
DEF_TYPE_TO_CHECK(And, &&)
DEF_TYPE_TO_CHECK(Or, ||)

namespace Not {
struct A { bool operator ! () const noexcept { return true; } };
struct B { bool operator ! () noexcept       { return true; } };
struct C { bool operator ! () const          { return true; } };
struct D { bool operator ! ()                { return true; } };
} /* not */

int main() {
    {
        using namespace And;

        // Test has_and_op_v.
        {

            static_assert(!has_and_op_v<O, O>);
            static_assert(!has_and_op_v<const B&, const B&>);

            static_assert(has_and_op_v<int, int>);
            static_assert(has_and_op_v<const A&, const A&>);
            static_assert(has_and_op_v<B, const B&>);

        }

        // Test has_nothrow_and_op_v.
        {

            static_assert(!has_nothrow_and_op_v<O, O>);
            static_assert(!has_nothrow_and_op_v<const B&, const B&>);
            static_assert(!has_nothrow_and_op_v<const C&, const C&>);

            static_assert(has_nothrow_and_op_v<int, int>);
            static_assert(has_nothrow_and_op_v<const A&, const A&>);
            static_assert(has_nothrow_and_op_v<B, const B&>);

        }
    }

    {
        using namespace Or;

        // Test has_or_op_v.
        {

            static_assert(!has_or_op_v<O, O>);
            static_assert(!has_or_op_v<const B&, const B&>);

            static_assert(has_or_op_v<int, int>);
            static_assert(has_or_op_v<const A&, const A&>);
            static_assert(has_or_op_v<B, const B&>);

        }

        // Test has_nothrow_or_op_v.
        {

            static_assert(!has_nothrow_or_op_v<O, O>);
            static_assert(!has_nothrow_or_op_v<const B&, const B&>);
            static_assert(!has_nothrow_or_op_v<const C&, const C&>);

            static_assert(has_nothrow_or_op_v<int, int>);
            static_assert(has_nothrow_or_op_v<const A&, const A&>);
            static_assert(has_nothrow_or_op_v<B, const B&>);

        }
    }

    {
        using namespace Not;

        // Test has_not_op_v.
        {

            static_assert(!has_not_op_v<O>);
            static_assert(!has_not_op_v<const B&>);

            static_assert(has_not_op_v<int>);
            static_assert(has_not_op_v<const A&>);
            static_assert(has_not_op_v<B>);

        }

        // Test has_nothrow_not_op_v.
        {

            static_assert(!has_nothrow_not_op_v<O>);
            static_assert(!has_nothrow_not_op_v<const B&>);
            static_assert(!has_nothrow_not_op_v<const C&>);

            static_assert(has_nothrow_not_op_v<int>);
            static_assert(has_nothrow_not_op_v<const A&>);
            static_assert(has_nothrow_not_op_v<B>);

        }
    }
}
