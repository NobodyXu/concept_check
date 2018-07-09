#include "../../include/concepts/is_class_or_union_v.hpp"
using namespace nxwheels;

enum unscoped_e {};
enum class scoped_e {};
struct S {};
union U {};
struct incomplete_type;

int main() {
    static_assert(!is_class_or_union_v<unscoped_e>);
    static_assert(!is_class_or_union_v<scoped_e>);

    static_assert(is_class_or_union_v<S>);
    static_assert(is_class_or_union_v<U>);
    static_assert(is_class_or_union_v<incomplete_type>);
}
