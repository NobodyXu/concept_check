#include "../../../../include/concepts/is_same.hpp"
#include "../../../../include/concepts/type_properties/member/has_ntype_type_v.hpp"
using namespace nxwheels;

struct A {
    typedef A type;
};
int main() {
    assert_same<ntype_type_t<A>, A>();
    static_assert(has_ntype_type_v<A>);
}
