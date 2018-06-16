#include <type_traits>
#include <cstddef>
#include "../src/usefull_types.hpp"
using namespace nxwheels::concept_check;

int main() {
    static_assert(std::is_same<std::size_t, size_t>{}());
    static_assert(std::is_same<std::ptrdiff_t, ptrdiff_t>{}());
}
