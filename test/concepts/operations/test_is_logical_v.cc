#include "../../../include/concepts/operations/is_logical_v.hpp"
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

        // Test is_andable_v.
        {

            static_assert(!is_andable_v<O, O>);
            static_assert(!is_andable_v<const B&, const B&>);

            static_assert(is_andable_v<int, int>);
            static_assert(is_andable_v<const A&, const A&>);
            static_assert(is_andable_v<B, const B&>);

        }

        // Test is_nothrow_andable_v.
        {

            static_assert(!is_nothrow_andable_v<O, O>);
            static_assert(!is_nothrow_andable_v<const B&, const B&>);
            static_assert(!is_nothrow_andable_v<const C&, const C&>);

            static_assert(is_nothrow_andable_v<int, int>);
            static_assert(is_nothrow_andable_v<const A&, const A&>);
            static_assert(is_nothrow_andable_v<B, const B&>);

        }
    }

    {
        using namespace Or;

        // Test is_orable_v.
        {

            static_assert(!is_orable_v<O, O>);
            static_assert(!is_orable_v<const B&, const B&>);

            static_assert(is_orable_v<int, int>);
            static_assert(is_orable_v<const A&, const A&>);
            static_assert(is_orable_v<B, const B&>);

        }

        // Test is_nothrow_orable_v.
        {

            static_assert(!is_nothrow_orable_v<O, O>);
            static_assert(!is_nothrow_orable_v<const B&, const B&>);
            static_assert(!is_nothrow_orable_v<const C&, const C&>);

            static_assert(is_nothrow_orable_v<int, int>);
            static_assert(is_nothrow_orable_v<const A&, const A&>);
            static_assert(is_nothrow_orable_v<B, const B&>);

        }
    }

    {
        using namespace Not;

        // Test is_notable_v.
        {

            static_assert(!is_notable_v<O>);
            static_assert(!is_notable_v<const B&>);

            static_assert(is_notable_v<int>);
            static_assert(is_notable_v<const A&>);
            static_assert(is_notable_v<B>);

        }

        // Test is_nothrow_notable_v.
        {

            static_assert(!is_nothrow_notable_v<O>);
            static_assert(!is_nothrow_notable_v<const B&>);
            static_assert(!is_nothrow_notable_v<const C&>);

            static_assert(is_nothrow_notable_v<int>);
            static_assert(is_nothrow_notable_v<const A&>);
            static_assert(is_nothrow_notable_v<B>);

        }
    }
}
