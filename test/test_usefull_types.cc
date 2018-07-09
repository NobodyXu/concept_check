#include <type_traits>
#include <cstddef>
#include "../include/usefull_types.hpp"
using namespace nxwheels;

int main() {
    static_assert(std::is_same<std::size_t, size_t>{}());
    static_assert(std::is_same<std::ptrdiff_t, ptrdiff_t>{}());
}
