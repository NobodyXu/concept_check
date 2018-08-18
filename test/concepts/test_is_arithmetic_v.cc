#include "../../include/concepts/is_arithmetic_v.hpp"
using namespace nxwheels;

int main() {
    static_assert(is_arithmetic_v<char>);
    static_assert(is_arithmetic_v<int>);
    static_assert(is_arithmetic_v<unsigned long long>);
}
