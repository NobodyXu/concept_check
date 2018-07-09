#include "../../include/concepts/is_primitive_function_pointer_v.hpp"
using namespace nxwheels;

int main() {
    static_assert(!is_primitive_function_pointer_v<int *>);
    static_assert(!is_primitive_function_pointer_v<int>);

    static_assert(is_primitive_function_pointer_v<int (*)()>);
    static_assert(is_primitive_function_pointer_v<int (*)() noexcept>);
}
