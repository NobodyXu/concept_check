#include "../../../../include/concepts/type_properties/operations/is_arrowable_v.hpp"
#include "../../../../include/enable_if.hpp"
using namespace nxwheels;

struct A {};

struct B {
    A *p;
    A* operator -> ();
};
struct C {
    A *p;
    A* operator -> () noexcept;
};

struct D {
    A *p;
    template <class = void>
    A* operator -> ();
};
struct E {
    A *p;
    template <class = void>
    A* operator -> () noexcept;
};

struct F {
    A *p;
    A* operator -> ();
    template <class = void>
    A* operator -> ();
};
struct G {
    A *p;
    A* operator -> () noexcept;
    template <class = void>
    A* operator -> () noexcept;
};

int main() {
    // Test has_builtin_arrow_v.
    {

        static_assert(!has_builtin_arrow_v<void>);
        static_assert(!has_builtin_arrow_v<A>);
        static_assert(!has_builtin_arrow_v<int*>);

        static_assert(has_builtin_arrow_v<A*>);

    }

    // Test has_member_function_arrow_overload_v.
    {

        static_assert(!has_member_function_arrow_overload_v<void>);
        static_assert(!has_member_function_arrow_overload_v<A>);
        static_assert(!has_member_function_arrow_overload_v<int*>);
        static_assert(!has_member_function_arrow_overload_v<A*>);

        static_assert(!has_member_function_arrow_overload_v<D>);
        static_assert(!has_member_function_arrow_overload_v<E>);
        static_assert(!has_member_function_arrow_overload_v<F>);
        static_assert(!has_member_function_arrow_overload_v<G>);

        static_assert(has_member_function_arrow_overload_v<B>);
        static_assert(has_member_function_arrow_overload_v<C>);

    }

    // Test has_member_function_arrow_template_overload_v.
    {

        static_assert(!has_member_function_arrow_template_overload_v<void>);
        static_assert(!has_member_function_arrow_template_overload_v<A>);
        static_assert(!has_member_function_arrow_template_overload_v<int*>);
        static_assert(!has_member_function_arrow_template_overload_v<A*>);

        static_assert(!has_member_function_arrow_template_overload_v<B>);
        static_assert(!has_member_function_arrow_template_overload_v<C>);

        static_assert(has_member_function_arrow_template_overload_v<D>);
        static_assert(has_member_function_arrow_template_overload_v<E>);
        static_assert(has_member_function_arrow_template_overload_v<F>);
        static_assert(has_member_function_arrow_template_overload_v<G>);

    }

    // Test is_arrowable_v..
    {

        static_assert(!is_arrowable_v<void>);
        static_assert(!is_arrowable_v<A>);
        static_assert(!is_arrowable_v<int*>);

        static_assert(is_arrowable_v<A*>);
        static_assert(is_arrowable_v<B>);
        static_assert(is_arrowable_v<C>);

        static_assert(is_arrowable_v<D>);
        static_assert(is_arrowable_v<E>);
        static_assert(is_arrowable_v<F>);
        static_assert(is_arrowable_v<G>);

    }

}
