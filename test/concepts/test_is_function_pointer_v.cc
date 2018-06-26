#include "../../src/concepts/is_function_pointer_v.hpp"
using namespace nxwheels::concept_check;

int main() {
    static_assert(!is_function_pointer_v<int *>);
    static_assert(!is_function_pointer_v<int>);

    static_assert(is_function_pointer_v<int (*)()>);
    static_assert(is_function_pointer_v<int (*)() noexcept>);
}
