#include "../../../../src/concepts/type_properties/operations/is_destructible_v.hpp"
using namespace nxwheels::concept_check;

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

namespace test_friend {
struct friend_t;

struct friend_destructible {
    friend void friend_f();
    friend friend_t;
private:
    ~friend_destructible() = default;
};

void friend_f() { friend_destructible{}; }
struct friend_t {};
} /* test_friend */

int main() {
    static_assert(is_destructible_v<int>);
    static_assert(is_destructible_v<int*>);
    static_assert(is_destructible_v<S>);
    static_assert(is_destructible_v<U>);

    static_assert(!is_destructible_v<undestructible>);
    static_assert(!is_destructible_v<incomplete_type>);
}
