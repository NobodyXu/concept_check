#include "../../include/concepts/is_void_v.hpp"
struct A {};
int main() {
    static_assert(nxwheels::is_void_v<void>);
    static_assert(!nxwheels::is_void_v<int>);
    static_assert(!nxwheels::is_void_v<A>);
}
