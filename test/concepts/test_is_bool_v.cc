#include "../../src/concepts/is_bool_v.hpp"
using namespace nxwheels::concept_check;
struct A {};
int main() {
    static_assert(is_bool_v<bool>);

    static_assert(!is_bool_v<int>);
    static_assert(!is_bool_v<A>);
}
