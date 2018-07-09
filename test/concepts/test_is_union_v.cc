#include "../../include/concepts/is_union_v.hpp"
using namespace nxwheels;

struct S {};
union U {
    int i;
    char c;
};

int main() {
    static_assert(!is_union_v<int>);
    static_assert(!is_union_v<S>);

    static_assert(is_union_v<U>);
}
