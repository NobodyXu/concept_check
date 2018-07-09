#include "../../../include/concepts/type_properties/is_pointable_v.hpp"
using namespace nxwheels;

struct S {};
union U {};
enum unscoped_e {};
enum class scoped_e {};

int main() {
    // Test is_pointable_v.
    static_assert(!is_pointable_v<void () const volatile && noexcept>);

    static_assert(is_pointable_v<int>);
    static_assert(is_pointable_v<int*>);
    static_assert(is_pointable_v<void>);
    static_assert(is_pointable_v<S>);
    static_assert(is_pointable_v<U>);
    static_assert(is_pointable_v<unscoped_e>);
    static_assert(is_pointable_v<scoped_e>);
    static_assert(is_pointable_v<void () noexcept>);
}
