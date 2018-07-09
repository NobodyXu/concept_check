#include "../../../../include/concepts/type_properties/operations/is_destructible_v.hpp"
using namespace nxwheels;

struct S {
    int i;
    char c;
};
union U {
    int i;
    char c;
};
struct undestructible {
    ~undestructible() = delete;
};
struct incomplete_type;

int main() {
    // Test is_destructible_v.
    static_assert(is_destructible_v<int>);
    static_assert(is_destructible_v<int*>);
    static_assert(is_destructible_v<S>);
    static_assert(is_destructible_v<U>);

    static_assert(!is_destructible_v<undestructible>);
    static_assert(!is_destructible_v<incomplete_type>);

    // Test is_nothrow_destructible_v.
    static_assert(is_nothrow_destructible_v<int>);
    static_assert(is_nothrow_destructible_v<S>);
    static_assert(is_nothrow_destructible_v<U>);

    static_assert(!is_nothrow_destructible_v<undestructible>);
    static_assert(!is_nothrow_destructible_v<incomplete_type>);
}
