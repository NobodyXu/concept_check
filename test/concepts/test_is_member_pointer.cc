#include "../../src/concepts/is_member_pointer.hpp"
#include "../../src/concepts/is_same.hpp"
using namespace nxwheels::concept_check;

struct A {
    int i;
    void F() {}
};

int main() {
    // Test is_member_pointer_v.
    static_assert(!is_member_pointer_v<int>);
    static_assert(!is_member_pointer_v<int*>);
    static_assert(!is_member_pointer_v<int (*)()>);

    static_assert(is_member_pointer_v<int A::*>);
    static_assert(is_member_pointer_v<void (A::*)()>);

    // Test pointed_to_by_member_pointer_t.
    assert_same<pointed_to_by_member_pointer_t<int A::*>, int *>();
    assert_same<pointed_to_by_member_pointer_t<void (A::*)()>, void (*)()>();

    // Test class_member_pointer_belonged_to_t.
    assert_same<class_member_pointer_belonged_to_t<int A::*>, A>();
    assert_same<class_member_pointer_belonged_to_t<void (A::*)()>, A>();
}
