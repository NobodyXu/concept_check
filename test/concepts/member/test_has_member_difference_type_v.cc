#include "../../../include/concepts/member/has_member_type_difference_type_v.hpp"
using namespace nxwheels;
#include "../../four_types.hpp"

struct A {
    typedef int difference_type;
};

int main() {
    static_assert(!has_member_type_difference_type_v<void>);

    static_assert(!has_member_type_difference_type_v<int>);

    static_assert(!has_member_type_difference_type_v<S>);

    static_assert(has_member_type_difference_type_v<A>);
}
