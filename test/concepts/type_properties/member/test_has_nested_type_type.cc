#include "../../../../src/concepts/is_same.hpp"
#include "../../../../src/concepts/type_properties/member/has_nested_type_type.hpp"
using namespace nxwheels::concept_check;

struct A {
    typedef A type;
};
int main() {
    assert_same<nested_type_type_t<A>, A>();
    static_assert(has_nested_type_type_v<A>);
}
