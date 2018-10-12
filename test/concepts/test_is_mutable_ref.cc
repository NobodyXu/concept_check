#include "../../include/concepts/is_mutable_ref.hpp"
using namespace nxwheels;

int main() {
    static_assert(!is_mutable_ref_v<int>);
    static_assert(!is_mutable_ref_v<const int>);
    static_assert(!is_mutable_ref_v<volatile int>);
    static_assert(!is_mutable_ref_v<const volatile int>);

    static_assert(!is_mutable_ref_v<const int&>);
    static_assert(!is_mutable_ref_v<const volatile int&>);

    static_assert(!is_mutable_ref_v<const int&&>);
    static_assert(!is_mutable_ref_v<const volatile int&&>);

    static_assert(is_mutable_ref_v<int&>);
    static_assert(is_mutable_ref_v<int&&>);

    static_assert(is_mutable_ref_v<volatile int&>);
    static_assert(is_mutable_ref_v<volatile int&&>);
}
