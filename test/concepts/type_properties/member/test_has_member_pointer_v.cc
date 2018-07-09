#include "../../../../include/concepts/type_properties/member/has_member_pointer_v.hpp"
using namespace nxwheels;

struct s {};
union u {};
int main() {
    static_assert(!has_member_pointer_v<int>);

    static_assert(has_member_pointer_v<s>);
    static_assert(has_member_pointer_v<u>);
}
