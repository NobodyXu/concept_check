#include "../../../../include/concepts/type_properties/operations/is_pointer_to_member_accessable_v.hpp"
using namespace nxwheels;

struct A {
    int i;
    int F() { return 0; }
    int F(int) noexcept { return 0; }
    int F(bool) & noexcept { return 0; }
    int F(bool) && { return 1; }
};
struct B {
    A *a;
    template <class R, class T>
    decltype(auto) operator ->* (R T::*p) { return a->*p; }
};
struct C {
    A *a;
    template <class R, class T>
    decltype(auto) operator ->* (R T::*p) noexcept { return a->*p; }
};

int main() {
    // Test is_pointer_to_data_member_accessable_v.
    {

        static_assert(!is_pointer_to_data_member_accessable_v<int*, int A::*>);

        static_assert(is_pointer_to_data_member_accessable_v<A*, int A::*>);

        static_assert(is_pointer_to_data_member_accessable_v<B, int A::*>);
        static_assert(is_pointer_to_data_member_accessable_v<C, int A::*>);

    }

    // Test __is_pointer_to_function_member_accessable_v.
    {

        static_assert(!__is_pointer_to_function_member_accessable_v<A*, int A::*>);
        static_assert(!__is_pointer_to_function_member_accessable_v<int*, int A::*>);
        static_assert(!__is_pointer_to_function_member_accessable_v<int*, int (A::*)()>);

        static_assert(!__is_pointer_to_function_member_accessable_v<A*, int (A::*)(bool) &&, bool>);

        static_assert(__is_pointer_to_function_member_accessable_v<A*, int (A::*)(void)>);
        static_assert(__is_pointer_to_function_member_accessable_v<A*, int (A::*)(int), int>);
        static_assert(__is_pointer_to_function_member_accessable_v<A*, int (A::*)(bool) &, bool>);

    }

    // Test is_pointer_to_function_member_accessable_v.
    {

        static_assert(!is_pointer_to_function_member_accessable_v<A*, int A::*>);
        static_assert(!is_pointer_to_function_member_accessable_v<int*, int A::*>);
        static_assert(!is_pointer_to_function_member_accessable_v<int*, int (A::*)()>);

        static_assert(!is_pointer_to_function_member_accessable_v<A*, int (A::*)(bool) &&>);

        static_assert(is_pointer_to_function_member_accessable_v<A*, int (A::*)(void)>);
        static_assert(is_pointer_to_function_member_accessable_v<A*, int (A::*)(int)>);
        static_assert(is_pointer_to_function_member_accessable_v<A*, int (A::*)(bool) &>);

    }

    // Test is_nothrow_pointer_to_data_member_accessable_v.
    {

        static_assert(!is_nothrow_pointer_to_data_member_accessable_v<B, int A::*>);

        static_assert(is_nothrow_pointer_to_data_member_accessable_v<A*, int A::*>);
        static_assert(is_nothrow_pointer_to_data_member_accessable_v<C, int A::*>);

    }

    // Test __is_nothrow_pointer_to_function_member_accessable_v.
    {

        static_assert(__is_nothrow_pointer_to_function_member_accessable_v<A*, int (A::*)(int) noexcept, int>);
        static_assert(__is_nothrow_pointer_to_function_member_accessable_v<A*, int (A::*)(bool) & noexcept, bool>);

    }

    // Test is_nothrow_pointer_to_function_member_accessable_v.
    {

        static_assert(!is_nothrow_pointer_to_function_member_accessable_v<A*, int A::*>);
        static_assert(!is_nothrow_pointer_to_function_member_accessable_v<int*, int A::*>);
        static_assert(!is_nothrow_pointer_to_function_member_accessable_v<int*, int (A::*)()>);

        static_assert(!is_nothrow_pointer_to_function_member_accessable_v<A*, int (A::*)(bool) &&>);
        static_assert(!is_nothrow_pointer_to_function_member_accessable_v<A*, int (A::*)(void)>);

        static_assert(is_nothrow_pointer_to_function_member_accessable_v<A*, int (A::*)(int) noexcept>);
        static_assert(is_nothrow_pointer_to_function_member_accessable_v<A*, int (A::*)(bool) & noexcept>);

    }

    // Test is_pointer_to_member_accessable_v.
    {

        static_assert(!is_pointer_to_member_accessable_v<int*, int A::*>);
        static_assert(!is_pointer_to_member_accessable_v<int*, int A::*>);
        static_assert(!is_pointer_to_member_accessable_v<int*, int (A::*)()>);

        static_assert(!is_pointer_to_member_accessable_v<A*, int (A::*)(bool) &&>);

        static_assert(is_pointer_to_member_accessable_v<A*, int (A::*)(void)>);
        static_assert(is_pointer_to_member_accessable_v<A*, int (A::*)(int)>);
        static_assert(is_pointer_to_member_accessable_v<A*, int (A::*)(bool) &>);

        static_assert(is_pointer_to_member_accessable_v<A*, int A::*>);
        static_assert(is_pointer_to_member_accessable_v<B, int A::*>);
        static_assert(is_pointer_to_member_accessable_v<C, int A::*>);

    }

    // Test is_nothrow_pointer_to_member_accessable_v.
    {

        static_assert(!is_nothrow_pointer_to_member_accessable_v<int*, int A::*>);
        static_assert(!is_nothrow_pointer_to_member_accessable_v<int*, int A::*>);
        static_assert(!is_nothrow_pointer_to_member_accessable_v<int*, int (A::*)()>);

        static_assert(!is_nothrow_pointer_to_member_accessable_v<A*, int (A::*)(bool) &&>);

        static_assert(!is_nothrow_pointer_to_member_accessable_v<A*, int (A::*)(void)>);

        static_assert(is_nothrow_pointer_to_member_accessable_v<A*, int (A::*)(int) noexcept>);
        static_assert(is_nothrow_pointer_to_member_accessable_v<A*, int (A::*)(bool) & noexcept>);

        static_assert(is_pointer_to_member_accessable_v<A*, int A::*>);
        static_assert(is_pointer_to_member_accessable_v<B, int A::*>);
        static_assert(is_pointer_to_member_accessable_v<C, int A::*>);

    }

}
