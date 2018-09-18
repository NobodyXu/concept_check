#ifndef __nobodyxu_concept_check_function_traits_HPP__
# define __nobodyxu_concept_check_function_traits_HPP__

# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class ...Args> struct Argslist {};

template <class T>
struct function_traits {
    CONCEPT_T is_function_v = false;

    CONCEPT_T is_const_qualified_v = false;
    CONCEPT_T is_volatile_qualified_v = false;
    CONCEPT_T is_lvalue_reference_qualified_v = false;
    CONCEPT_T is_rvalue_reference_qualified_v = false;
    CONCEPT_T is_cvref_qualified_v = false;

    CONCEPT_T is_noexcept_qualified_v = false;
};

# define DEF_ARG_OP()\
    using Argslist_t = Argslist<Args...>;\
    template <template <class...> class Op>\
    using apply_args_to_t = Op<Args...>

// The basic scenrio.
template <class R, class ...Args, bool is_noexcept>
struct function_traits<R (Args...) noexcept(is_noexcept)> {
    CONCEPT_T is_function_v = true;

    CONCEPT_T is_const_qualified_v = false;
    CONCEPT_T is_volatile_qualified_v = false;
    CONCEPT_T is_lvalue_reference_qualified_v = false;
    CONCEPT_T is_rvalue_reference_qualified_v = false;
    CONCEPT_T is_cvref_qualified_v = false;

    CONCEPT_T is_noexcept_qualified_v = is_noexcept;

    DEF_ARG_OP();
    using ret_t = R;
    using add_pointer_t = R (*)(Args...) noexcept(is_noexcept);
};

// Below are the specializations for function type deduced from member function pointer.
// const volatile & &&
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) const noexcept(is_noexcept_v)> {
    CONCEPT_T is_function_v = true;

    CONCEPT_T is_const_qualified_v = true;
    CONCEPT_T is_volatile_qualified_v = false;
    CONCEPT_T is_lvalue_reference_qualified_v = false;
    CONCEPT_T is_rvalue_reference_qualified_v = false;
    CONCEPT_T is_cvref_qualified_v = true;

    CONCEPT_T is_noexcept_qualified_v = is_noexcept_v;

    DEF_ARG_OP();
    using ret_t = R;
    using add_pointer_t = R (Args...) const noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) const & noexcept(is_noexcept_v)> {
    CONCEPT_T is_function_v = true;

    CONCEPT_T is_const_qualified_v = true;
    CONCEPT_T is_volatile_qualified_v = false;
    CONCEPT_T is_lvalue_reference_qualified_v = true;
    CONCEPT_T is_rvalue_reference_qualified_v = false;
    CONCEPT_T is_cvref_qualified_v = true;

    CONCEPT_T is_noexcept_qualified_v = is_noexcept_v;

    DEF_ARG_OP();
    using ret_t = R;
    using add_pointer_t = R (Args...) const & noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) const && noexcept(is_noexcept_v)> {
    CONCEPT_T is_function_v = true;

    CONCEPT_T is_const_qualified_v = true;
    CONCEPT_T is_volatile_qualified_v = false;
    CONCEPT_T is_lvalue_reference_qualified_v = false;
    CONCEPT_T is_rvalue_reference_qualified_v = true;
    CONCEPT_T is_cvref_qualified_v = true;

    CONCEPT_T is_noexcept_qualified_v = is_noexcept_v;

    DEF_ARG_OP();
    using ret_t = R;
    using add_pointer_t = R (Args...) const && noexcept(is_noexcept_v);
};

template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) volatile noexcept(is_noexcept_v)> {
    CONCEPT_T is_function_v = true;

    CONCEPT_T is_const_qualified_v = false;
    CONCEPT_T is_volatile_qualified_v = true;
    CONCEPT_T is_lvalue_reference_qualified_v = false;
    CONCEPT_T is_rvalue_reference_qualified_v = false;
    CONCEPT_T is_cvref_qualified_v = true;

    CONCEPT_T is_noexcept_qualified_v = is_noexcept_v;

    DEF_ARG_OP();
    using ret_t = R;
    using add_pointer_t = R (Args...) volatile noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) volatile & noexcept(is_noexcept_v)> {
    CONCEPT_T is_function_v = true;

    CONCEPT_T is_const_qualified_v = false;
    CONCEPT_T is_volatile_qualified_v = true;
    CONCEPT_T is_lvalue_reference_qualified_v = true;
    CONCEPT_T is_rvalue_reference_qualified_v = false;
    CONCEPT_T is_cvref_qualified_v = true;

    CONCEPT_T is_noexcept_qualified_v = is_noexcept_v;

    DEF_ARG_OP();
    using ret_t = R;
    using add_pointer_t = R (Args...) volatile & noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) volatile && noexcept(is_noexcept_v)> {
    CONCEPT_T is_function_v = true;

    CONCEPT_T is_const_qualified_v = false;
    CONCEPT_T is_volatile_qualified_v = true;
    CONCEPT_T is_lvalue_reference_qualified_v = false;
    CONCEPT_T is_rvalue_reference_qualified_v = true;
    CONCEPT_T is_cvref_qualified_v = true;

    CONCEPT_T is_noexcept_qualified_v = is_noexcept_v;

    DEF_ARG_OP();
    using ret_t = R;
    using add_pointer_t = R (Args...) volatile && noexcept(is_noexcept_v);
};

template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) & noexcept(is_noexcept_v)> {
    CONCEPT_T is_function_v = true;

    CONCEPT_T is_const_qualified_v = false;
    CONCEPT_T is_volatile_qualified_v = false;
    CONCEPT_T is_lvalue_reference_qualified_v = true;
    CONCEPT_T is_rvalue_reference_qualified_v = false;
    CONCEPT_T is_cvref_qualified_v = true;

    CONCEPT_T is_noexcept_qualified_v = is_noexcept_v;

    DEF_ARG_OP();
    using ret_t = R;
    using add_pointer_t = R (Args...) & noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) && noexcept(is_noexcept_v)> {
    CONCEPT_T is_function_v = true;

    CONCEPT_T is_const_qualified_v = false;
    CONCEPT_T is_volatile_qualified_v = false;
    CONCEPT_T is_lvalue_reference_qualified_v = false;
    CONCEPT_T is_rvalue_reference_qualified_v = true;
    CONCEPT_T is_cvref_qualified_v = true;

    CONCEPT_T is_noexcept_qualified_v = is_noexcept_v;

    DEF_ARG_OP();
    using ret_t = R;
    using add_pointer_t = R (Args...) && noexcept(is_noexcept_v);
};

template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) const volatile noexcept(is_noexcept_v)> {
    CONCEPT_T is_function_v = true;

    CONCEPT_T is_const_qualified_v = true;
    CONCEPT_T is_volatile_qualified_v = true;
    CONCEPT_T is_lvalue_reference_qualified_v = false;
    CONCEPT_T is_rvalue_reference_qualified_v = false;
    CONCEPT_T is_cvref_qualified_v = true;

    CONCEPT_T is_noexcept_qualified_v = is_noexcept_v;

    DEF_ARG_OP();
    using ret_t = R;
    using add_pointer_t = R (Args...) const volatile noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) const volatile & noexcept(is_noexcept_v)> {
    CONCEPT_T is_function_v = true;

    CONCEPT_T is_const_qualified_v = true;
    CONCEPT_T is_volatile_qualified_v = true;
    CONCEPT_T is_lvalue_reference_qualified_v = true;
    CONCEPT_T is_rvalue_reference_qualified_v = false;
    CONCEPT_T is_cvref_qualified_v = true;

    CONCEPT_T is_noexcept_qualified_v = is_noexcept_v;

    DEF_ARG_OP();
    using ret_t = R;
    using add_pointer_t = R (Args...) const volatile & noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) const volatile && noexcept(is_noexcept_v)> {
    CONCEPT_T is_function_v = true;

    CONCEPT_T is_const_qualified_v = true;
    CONCEPT_T is_volatile_qualified_v = true;
    CONCEPT_T is_lvalue_reference_qualified_v = false;
    CONCEPT_T is_rvalue_reference_qualified_v = true;
    CONCEPT_T is_cvref_qualified_v = true;

    CONCEPT_T is_noexcept_qualified_v = is_noexcept_v;

    DEF_ARG_OP();
    using ret_t = R;
    using add_pointer_t = R (Args...) const volatile && noexcept(is_noexcept_v);
};

# undef DEF_ARG_OP

template <class T> constexpr const static inline bool is_function_v = function_traits<T>::is_function_v;
template <class T> constexpr const static inline bool is_nonthrow_function_v = function_traits<T>::is_noexcept_qualified_v;
template <class T> constexpr const static inline bool is_function_cvref_qualified_v = function_traits<T>::is_cvref_qualified_v;

template <class T> using Argslist_of_function_t = typename function_traits<T>::Argslist_t;
template <class T, template <class...> class Op> using apply_function_args_to_t = typename function_traits<T>::template apply_args_to_t<Op>;

template <class T> using ret_t_of_function = typename function_traits<T>::ret_t;
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
