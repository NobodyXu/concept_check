#include "../../src/concepts/is_volatile.hpp"
using namespace nxwheels::concept_check;

int main() {
    static_assert(!is_volatile_v<int>);

    static_assert(is_volatile_v<volatile int>);
    static_assert(is_volatile_v<const volatile int>);
}
