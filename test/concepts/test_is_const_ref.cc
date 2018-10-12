#include "../../include/concepts/is_const_ref.hpp"
using namespace nxwheels;

int main() {
    static_assert(!is_const_ref_v<int>);
    static_assert(!is_const_ref_v<const int>);
    static_assert(!is_const_ref_v<int&>);
    static_assert(!is_const_ref_v<int&&>);

    static_assert(is_const_ref_v<const int&>);
    static_assert(is_const_ref_v<const int&&>);
}
