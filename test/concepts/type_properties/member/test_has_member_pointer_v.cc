#include "../../../../src/concepts/type_properties/member/has_member_pointer_v.hpp"
using namespace nxwheels::concept_check;

struct s {}
;
union u {};
int main() {
    static_assert(!has_member_pointer_v<int>);

    static_assert(has_member_pointer_v<s>);
    static_assert(has_member_pointer_v<u>);
}
