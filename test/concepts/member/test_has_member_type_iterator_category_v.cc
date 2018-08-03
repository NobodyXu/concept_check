#include "../../../include/concepts/member/has_member_type_iterator_category_v.hpp"
using namespace nxwheels;
#include "../../four_types.hpp"

struct A {
    typedef int iterator_category;
};

int main() {
    static_assert(!has_member_type_iterator_category_v<void>);
    static_assert(!has_member_type_iterator_category_v<int>);
    static_assert(!has_member_type_iterator_category_v<S>);
    static_assert(!has_member_type_iterator_category_v<U>);
    static_assert(!has_member_type_iterator_category_v<unscoped_e>);
    static_assert(!has_member_type_iterator_category_v<scoped_e>);

    static_assert(has_member_type_iterator_category_v<A>);
}
