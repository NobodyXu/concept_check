#include "../../include/concepts/is_arithmetic_v.hpp"
using namespace nxwheels;

#include <utility>
using std::swap;

int main() {
    static_assert(is_arithmetic_v<char>);
    static_assert(is_arithmetic_v<int>);
    static_assert(is_arithmetic_v<unsigned long long>);
}
