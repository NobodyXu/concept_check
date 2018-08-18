#include "../../include/concepts/has_valid_iterator_traits_v.hpp"
using namespace nxwheels;

struct A {
    using difference_type   = int;
    using value_type        = int;
    using pointer           = int*;
    using reference         = int&;
    using iterator_category = std::input_iterator_tag;
};
struct should_fail1 {
    using difference_type   = A;
    using value_type        = int;
    using pointer           = int*;
    using reference         = int&;
    using iterator_category = std::input_iterator_tag;
};

int main() {
    static_assert(!has_valid_iterator_traits_v<should_fail1>);

    static_assert(has_valid_iterator_traits_v<int*>);
    static_assert(has_valid_iterator_traits_v<A>);
}
