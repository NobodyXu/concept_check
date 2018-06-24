#ifndef __nobodyxu_concept_check_function_traits_HPP__
# define __nobodyxu_concept_check_function_traits_HPP__
namespace nxwheels::concept_check {
template <class T>
struct function_traits {
    constexpr const static inline bool is_function_v = false;
};
// The basic scenrio.
template <class R, class ...Args, bool is_noexcept>
struct function_traits<R (Args...) noexcept(is_noexcept)> {
    constexpr const static inline bool is_function_v = true;

    constexpr const static inline bool is_const_qualified_v = false;
    constexpr const static inline bool is_volatile_qualified_v = false;
    constexpr const static inline bool is_lvalue_reference_qualified_v = false;
    constexpr const static inline bool is_rvalue_reference_qualified_v = false;
    constexpr const static inline bool is_noexcept_qualified_v = is_noexcept;

    using add_pointer_t = R (*)(Args...) noexcept(is_noexcept);
};

// Below are the specializations for function type deduced from member function pointer.
// const volatile & &&
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) const noexcept(is_noexcept_v)> {
    constexpr const static inline bool is_function_v = true;

    constexpr const static inline bool is_const_qualified_v = true;
    constexpr const static inline bool is_volatile_qualified_v = false;
    constexpr const static inline bool is_lvalue_reference_qualified_v = false;
    constexpr const static inline bool is_rvalue_reference_qualified_v = false;
    constexpr const static inline bool is_noexcept_qualified_v = is_noexcept_v;

    using add_pointer_t = R (Args...) const noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) const & noexcept(is_noexcept_v)> {
    constexpr const static inline bool is_function_v = true;

    constexpr const static inline bool is_const_qualified_v = true;
    constexpr const static inline bool is_volatile_qualified_v = false;
    constexpr const static inline bool is_lvalue_reference_qualified_v = true;
    constexpr const static inline bool is_rvalue_reference_qualified_v = false;
    constexpr const static inline bool is_noexcept_qualified_v = is_noexcept_v;

    using add_pointer_t = R (Args...) const & noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) const && noexcept(is_noexcept_v)> {
    constexpr const static inline bool is_function_v = true;

    constexpr const static inline bool is_const_qualified_v = true;
    constexpr const static inline bool is_volatile_qualified_v = false;
    constexpr const static inline bool is_lvalue_reference_qualified_v = false;
    constexpr const static inline bool is_rvalue_reference_qualified_v = true;
    constexpr const static inline bool is_noexcept_qualified_v = is_noexcept_v;

    using add_pointer_t = R (Args...) const && noexcept(is_noexcept_v);
};

template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) volatile noexcept(is_noexcept_v)> {
    constexpr const static inline bool is_function_v = true;

    constexpr const static inline bool is_const_qualified_v = false;
    constexpr const static inline bool is_volatile_qualified_v = true;
    constexpr const static inline bool is_lvalue_reference_qualified_v = false;
    constexpr const static inline bool is_rvalue_reference_qualified_v = false;
    constexpr const static inline bool is_noexcept_qualified_v = is_noexcept_v;

    using add_pointer_t = R (Args...) volatile noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) volatile & noexcept(is_noexcept_v)> {
    constexpr const static inline bool is_function_v = true;

    constexpr const static inline bool is_const_qualified_v = false;
    constexpr const static inline bool is_volatile_qualified_v = true;
    constexpr const static inline bool is_lvalue_reference_qualified_v = true;
    constexpr const static inline bool is_rvalue_reference_qualified_v = false;
    constexpr const static inline bool is_noexcept_qualified_v = is_noexcept_v;

    using add_pointer_t = R (Args...) volatile & noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) volatile && noexcept(is_noexcept_v)> {
    constexpr const static inline bool is_function_v = true;

    constexpr const static inline bool is_const_qualified_v = false;
    constexpr const static inline bool is_volatile_qualified_v = true;
    constexpr const static inline bool is_lvalue_reference_qualified_v = false;
    constexpr const static inline bool is_rvalue_reference_qualified_v = true;
    constexpr const static inline bool is_noexcept_qualified_v = is_noexcept_v;

    using add_pointer_t = R (Args...) volatile && noexcept(is_noexcept_v);
};

template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) & noexcept(is_noexcept_v)> {
    constexpr const static inline bool is_function_v = true;

    constexpr const static inline bool is_const_qualified_v = false;
    constexpr const static inline bool is_volatile_qualified_v = false;
    constexpr const static inline bool is_lvalue_reference_qualified_v = true;
    constexpr const static inline bool is_rvalue_reference_qualified_v = false;
    constexpr const static inline bool is_noexcept_qualified_v = is_noexcept_v;

    using add_pointer_t = R (Args...) & noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) && noexcept(is_noexcept_v)> {
    constexpr const static inline bool is_function_v = true;

    constexpr const static inline bool is_const_qualified_v = false;
    constexpr const static inline bool is_volatile_qualified_v = false;
    constexpr const static inline bool is_lvalue_reference_qualified_v = false;
    constexpr const static inline bool is_rvalue_reference_qualified_v = true;
    constexpr const static inline bool is_noexcept_qualified_v = is_noexcept_v;

    using add_pointer_t = R (Args...) && noexcept(is_noexcept_v);
};

template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) const volatile noexcept(is_noexcept_v)> {
    constexpr const static inline bool is_function_v = true;

    constexpr const static inline bool is_const_qualified_v = true;
    constexpr const static inline bool is_volatile_qualified_v = true;
    constexpr const static inline bool is_lvalue_reference_qualified_v = false;
    constexpr const static inline bool is_rvalue_reference_qualified_v = false;
    constexpr const static inline bool is_noexcept_qualified_v = is_noexcept_v;

    using add_pointer_t = R (Args...) const volatile noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) const volatile & noexcept(is_noexcept_v)> {
    constexpr const static inline bool is_function_v = true;

    constexpr const static inline bool is_const_qualified_v = true;
    constexpr const static inline bool is_volatile_qualified_v = true;
    constexpr const static inline bool is_lvalue_reference_qualified_v = true;
    constexpr const static inline bool is_rvalue_reference_qualified_v = false;
    constexpr const static inline bool is_noexcept_qualified_v = is_noexcept_v;

    using add_pointer_t = R (Args...) const volatile & noexcept(is_noexcept_v);
};
template <class R, class ...Args, bool is_noexcept_v>
struct function_traits<R (Args...) const volatile && noexcept(is_noexcept_v)> {
    constexpr const static inline bool is_function_v = true;

    constexpr const static inline bool is_const_qualified_v = true;
    constexpr const static inline bool is_volatile_qualified_v = true;
    constexpr const static inline bool is_lvalue_reference_qualified_v = false;
    constexpr const static inline bool is_rvalue_reference_qualified_v = true;
    constexpr const static inline bool is_noexcept_qualified_v = is_noexcept_v;

    using add_pointer_t = R (Args...) const volatile && noexcept(is_noexcept_v);
};

template <class T>
constexpr const static inline bool is_function_v = function_traits<T>::is_function_v;
} /* nxwheels::concept_check */
#endif
