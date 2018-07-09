#include "../../../../include/concepts/type_properties/member/has_pointer_to_member_v.hpp"
using namespace nxwheels;

struct s {};
union u {};
int main() {
    static_assert(!has_pointer_to_member_v<int>);

    static_assert(has_pointer_to_member_v<s>);
    static_assert(has_pointer_to_member_v<u>);
}
