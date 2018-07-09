#include "../../include/concepts/is_primitive_pointer.hpp"
using namespace nxwheels;

struct A {
    int i;
};

int main() {
    static_assert(!is_primitive_pointer_v<int>);
    static_assert(!is_primitive_pointer_v<A>);

    static_assert(is_primitive_pointer_v<int*>);
    static_assert(is_primitive_pointer_v<int (*)()>);
    static_assert(is_primitive_pointer_v<int (*)() noexcept>);
    static_assert(is_primitive_pointer_v<int A::*>);
}
