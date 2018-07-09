#include "../../../include/concepts/type_properties/is_const.hpp"
using namespace nxwheels;

int main() {
    static_assert(!is_const_v<int>);

    static_assert(is_const_v<const int>);
    static_assert(is_const_v<const volatile int>);
}
