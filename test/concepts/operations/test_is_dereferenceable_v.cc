#include "../../../include/concepts/operations/is_dereferenceable_v.hpp"
using namespace nxwheels;

struct S {};
struct S0 {
    int *i;
    auto operator * () const { return *i; }
};
struct S1 {
    int *i;
    auto operator * () const noexcept { return *i; }
};

int main() {
    // Test is_dereferenceable_v.
    {

        static_assert(!is_dereferenceable_v<int>);

        static_assert(is_dereferenceable_v<int*>);
        static_assert(is_dereferenceable_v<S0>);
        static_assert(is_dereferenceable_v<S1>);

    }

    // Test is_nothrow_dereferenceable_v.
    {

        static_assert(!is_nothrow_dereferenceable_v<int>);
        static_assert(!is_nothrow_dereferenceable_v<S0>);

        static_assert(is_nothrow_dereferenceable_v<int*>);
        static_assert(is_nothrow_dereferenceable_v<S1>);

    }

}
