#include "../../src/concepts/is_primitive_arithmetic_v.hpp"
using namespace nxwheels::concept_check;

int main() {
    static_assert(is_primitive_arithmetic_v<char>);
    static_assert(is_primitive_arithmetic_v<char16_t>);
    static_assert(is_primitive_arithmetic_v<char32_t>);

    static_assert(is_primitive_arithmetic_v<unsigned char>);
    static_assert(is_primitive_arithmetic_v<signed char>);
    static_assert(is_primitive_arithmetic_v<unsigned int>);
    static_assert(is_primitive_arithmetic_v<signed int>);

    static_assert(is_primitive_arithmetic_v<float>);
    static_assert(is_primitive_arithmetic_v<double>);
    static_assert(is_primitive_arithmetic_v<long double>);
}
