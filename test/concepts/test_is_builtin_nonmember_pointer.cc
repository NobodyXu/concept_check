#include "../../src/concepts/is_builtin_nonmember_pointer.hpp"
using namespace nxwheels::concept_check;

struct A {
    int i;
};

int main() {;
    static_assert(!is_builtin_nonmember_pointer_v<int>);
    static_assert(!is_builtin_nonmember_pointer_v<int A::*>);

    static_assert(is_builtin_nonmember_pointer_v<int*>);
    static_assert(is_builtin_nonmember_pointer_v<void*>);
    static_assert(is_builtin_nonmember_pointer_v<void**>);
}
