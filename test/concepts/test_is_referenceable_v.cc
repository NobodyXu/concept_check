#include "../../include/concepts/is_referenceable_v.hpp"
using namespace nxwheels;

struct S {};
union U {};
enum unscoped_e {};
enum class scoped_e {};

int main() {
    // Test is_referenceable_v.
    static_assert(!is_referenceable_v<void>);
    static_assert(!is_referenceable_v<void () const volatile && noexcept>);

    static_assert(is_referenceable_v<int>);
    static_assert(is_referenceable_v<int*>);
    static_assert(is_referenceable_v<S>);
    static_assert(is_referenceable_v<U>);
    static_assert(is_referenceable_v<unscoped_e>);
    static_assert(is_referenceable_v<scoped_e>);
    static_assert(is_referenceable_v<void () noexcept>);
}
