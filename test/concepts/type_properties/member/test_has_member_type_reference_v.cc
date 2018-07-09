#include "../../../../include/concepts/type_properties/member/has_member_type_reference_v.hpp"
using namespace nxwheels;
#include "../../../four_types.hpp"

struct A {
    typedef int reference;
};

int main() {
    static_assert(!has_member_type_reference_v<void>);
    static_assert(!has_member_type_reference_v<int>);
    static_assert(!has_member_type_reference_v<S>);
    static_assert(!has_member_type_reference_v<U>);
    static_assert(!has_member_type_reference_v<unscoped_e>);
    static_assert(!has_member_type_reference_v<scoped_e>);

    static_assert(has_member_type_reference_v<A>);
}
