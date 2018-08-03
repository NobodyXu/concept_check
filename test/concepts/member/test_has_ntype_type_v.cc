#include <type_traits>
#include "../../../include/concepts/member/has_ntype_type_v.hpp"
using namespace nxwheels;

struct A {
    typedef A type;
};
int main() {
    static_assert(std::is_same<ntype_type_t<A>, A>::value);
    static_assert(has_ntype_type_v<A>);
}
