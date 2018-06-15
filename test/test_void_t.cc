#include <type_traits>
#include "../src/void_t.hpp"
using namespace nxwheels::concept_check;

int main() {
    static_assert(std::is_same<void_t<int, char>, void>{}());
}
