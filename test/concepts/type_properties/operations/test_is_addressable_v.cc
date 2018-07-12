#include "../../../../include/concepts/type_properties/operations/is_addressable_v.hpp"
#include "../../../../include/enable_if.hpp"
using namespace nxwheels;

struct S {};
struct S0 {
    int *i;
    auto operator & () const { return *i; }
};
struct S1 {
    int *i;
    auto operator & () const noexcept { return *i; }
};

int main() {
    // Test is_addressable_v.
    {

        static_assert(is_addressable_v<int&>);
        static_assert(is_addressable_v<int*&>);
        static_assert(is_addressable_v<S0>);
        static_assert(is_addressable_v<S1>);

    }

    // Test is_nothrow_addressable_v.
    {

        static_assert(!is_nothrow_addressable_v<S0>);

        static_assert(is_nothrow_addressable_v<int&>);
        static_assert(is_nothrow_addressable_v<int*&>);
        static_assert(is_nothrow_addressable_v<S1>);

    }

}