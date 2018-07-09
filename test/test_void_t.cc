#include <type_traits>
#include "../include/void_t.hpp"
using namespace nxwheels;

int main() {
    static_assert(std::is_same<void_t<int, char>, void>{}());
}
