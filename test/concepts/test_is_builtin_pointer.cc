#include "../../include/concepts/is_builtin_pointer.hpp"
#include "../../include/concepts/is_same.hpp"
using namespace nxwheels;

struct A {
    int i;
};

int main() {
    // Test is_builtin_pointer_v.
    static_assert(!is_builtin_pointer_v<int>);

    static_assert(is_builtin_pointer_v<int A::*>);
    static_assert(is_builtin_pointer_v<int*>);
    static_assert(is_builtin_pointer_v<void*>);
    static_assert(is_builtin_pointer_v<void**>);

    // Test pointed_to_by_pointer_t.
    static_assert(is_same_v<pointed_to_by_pointer_t<int A::*>, pointed_to_by_pointer_t<int*>, int>);
}
