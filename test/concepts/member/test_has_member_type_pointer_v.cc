#include "../../../include/concepts/member/has_member_type_pointer_v.hpp"
using namespace nxwheels;
#include "../../four_types.hpp"

struct A {
    typedef int pointer;
};

int main() {
    static_assert(!has_member_type_pointer_v<void>);

    static_assert(!has_member_type_pointer_v<int>);

    static_assert(!has_member_type_pointer_v<S>);

    static_assert(has_member_type_pointer_v<A>);
}
