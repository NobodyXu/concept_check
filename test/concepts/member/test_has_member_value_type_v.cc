#include "../../../include/concepts/member/has_member_value_type_v.hpp"
using namespace nxwheels;
#include "../../four_types.hpp"

struct A {
    typedef int value_type;
};

int main() {
    static_assert(!has_member_value_type_v<void>);
    static_assert(!has_member_value_type_v<int>);
    static_assert(!has_member_value_type_v<S>);
    static_assert(!has_member_value_type_v<U>);
    static_assert(!has_member_value_type_v<unscoped_e>);
    static_assert(!has_member_value_type_v<scoped_e>);

    static_assert(has_member_value_type_v<A>);
}
