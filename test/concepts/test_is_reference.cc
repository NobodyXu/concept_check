#include "../../include/concepts/is_reference.hpp"
using namespace nxwheels;

int main() {
    static_assert(!is_reference_v<int>);
    static_assert(is_reference_v<int&>);
    static_assert(is_reference_v<int&&>);

    static_assert(!is_lvalue_reference_v<int>);
    static_assert(is_lvalue_reference_v<int&>);
    static_assert(!is_lvalue_reference_v<int&&>);

    static_assert(!is_rvalue_reference_v<int>);
    static_assert(!is_rvalue_reference_v<int&>);
    static_assert(is_rvalue_reference_v<int&&>);
}
