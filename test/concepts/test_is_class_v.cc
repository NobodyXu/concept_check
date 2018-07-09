#include "../../include/concepts/is_class_v.hpp"
using namespace nxwheels;

enum unscoped_e {};
enum class scoped_e {};
struct S {};
struct incomplete_class;
union U {};

int main() {
    static_assert(!is_class_v<int>);
    static_assert(!is_class_v<int*>);
    static_assert(!is_class_v<void>);
    static_assert(!is_class_v<unscoped_e>);
    static_assert(!is_class_v<scoped_e>);
    static_assert(!is_class_v<U>);

    static_assert(is_class_v<S>);
    static_assert(is_class_v<incomplete_class>);
}
