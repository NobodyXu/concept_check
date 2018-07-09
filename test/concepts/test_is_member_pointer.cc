#include "../../include/concepts/is_member_pointer.hpp"
#include "../../include/concepts/is_same.hpp"
using namespace nxwheels;

struct A {
    int i;
    void F() {}
    void F2() const volatile && noexcept {}
};

int main() {
    // Test is_member_pointer_v.
    static_assert(!is_member_pointer_v<int>);
    static_assert(!is_member_pointer_v<int*>);
    static_assert(!is_member_pointer_v<int (*)()>);

    static_assert(is_member_pointer_v<int A::*>);
    static_assert(is_member_pointer_v<void (A::*)()>);
    static_assert(is_member_pointer_v<void (A::*)() const volatile && noexcept>);

    // Test pointed_to_by_member_pointer_t.
    assert_same<pointed_to_by_member_pointer_t<int A::*>, int>();
    assert_same<pointed_to_by_member_pointer_t<void (A::*)()>, void ()>();
    assert_same<pointed_to_by_member_pointer_t<void (A::*)() const volatile && noexcept>, void () const volatile && noexcept>();

    // Test class_member_pointer_belonged_to_t.
    assert_same<class_member_pointer_belonged_to_t<int A::*>, A>();
    assert_same<class_member_pointer_belonged_to_t<void (A::*)()>, A>();
    assert_same<class_member_pointer_belonged_to_t<void (A::*)() const volatile && noexcept>, A>();

    // Test is_member_object_pointer_v.
    static_assert(is_member_object_pointer_v<int A::*>);
    static_assert(!is_member_object_pointer_v<void (A::*)()>);
    static_assert(!is_member_object_pointer_v<void (A::*)() const volatile && noexcept>);

    // Test is_member_object_pointer_v.
    static_assert(!is_member_function_pointer_v<int A::*>);
    static_assert(is_member_function_pointer_v<void (A::*)()>);
    static_assert(is_member_function_pointer_v<void (A::*)() const volatile && noexcept>);
}
