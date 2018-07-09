#include "../../../include/concepts/type_properties/is_volatile.hpp"
using namespace nxwheels;

int main() {
    static_assert(!is_volatile_v<int>);

    static_assert(is_volatile_v<volatile int>);
    static_assert(is_volatile_v<const volatile int>);
}
