#include <type_traits>
#include "../src/control_flow.hpp"
using namespace nxwheels::concept_check;
int main() {
    static_assert(std::is_same<if_t<0, int, char>, char>{}());
    static_assert(std::is_same<if_t<1, int, char>, int>{}());
}
