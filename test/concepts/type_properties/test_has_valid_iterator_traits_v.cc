#include "../../../include/concepts/type_properties/has_valid_iterator_traits_v.hpp"
using namespace nxwheels;

struct A {
    using difference_type   = int;
    using value_type        = int;
    using pointer           = int*;
    using reference         = int&;
    using iterator_category = std::input_iterator_tag;
};

int main() {
    static_assert(!has_valid_iterator_traits_member_type_v<int>);

    static_assert(has_valid_iterator_traits_member_type_v<int*>);
    static_assert(has_valid_iterator_traits_member_type_v<const int*>);

    static_assert(has_valid_iterator_traits_member_type_v<A>);
}
