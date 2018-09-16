#ifndef __nobodxu_concept_check_concepts_operations_is_arrowable_v_HPP__
# define __nobodxu_concept_check_concepts_operations_is_arrowable_v_HPP__

# include "../../function_traits.hpp"

# include "../is_builtin_pointer.hpp"
# include "../is_class_or_union_v.hpp"

# include "is_callable_v.hpp"

# include "def_convenient_macros.hpp"

namespace nxwheels {
# define DEF_CONCEPT template <class T> constexpr const static inline bool

template <class T> using member_function_arrow_overload_t          = decltype(&T::operator ->);
template <class T> using member_function_arrow_template_overload_t = decltype(&T::template operator -> <>);

template <class T> using member_function_arrow_ret_t          = ret_t_of_function< pointed_to_by_member_pointer_t<member_function_arrow_overload_t<T>> >;
template <class T> using member_function_arrow_template_ret_t = ret_t_of_function< pointed_to_by_member_pointer_t<member_function_arrow_template_overload_t<T>> >;

DEF_CONCEPT has_builtin_arrow_overload_v                  = is_builtin_pointer_v<T> && !is_function_v<pointed_to_by_pointer_t<T>>;

template <class T> struct is_builtin_arrowable:     false_type {};
template <class T> struct is_builtin_arrowable<T*>: bool_constant<is_class_or_union_v<T>> {};
DEF_CONCEPT is_builtin_arrowable_v = is_builtin_arrowable<T>::value;


DEF_CONCEPT has_member_function_arrow_overload_v          = []{
    if constexpr(is_detected_v<member_function_arrow_overload_t, T>)
        return std::is_pointer<member_function_arrow_ret_t<T>>{}();
    else
        return false;
}();
DEF_CONCEPT has_member_function_arrow_template_overload_v = []{
    if constexpr(is_detected_v<member_function_arrow_template_overload_t, T>)
        return std::is_pointer<member_function_arrow_template_ret_t<T>>{}();
    else
        return false;
}();

DEF_CONCEPT is_member_function_arrowable_v = []{
    if constexpr(has_member_function_arrow_overload_v<T>)
        return is_class_or_union_v<std::remove_pointer_t<member_function_arrow_ret_t<T>>>;
    else
        return false;
}();
DEF_CONCEPT is_member_function_template_arrowable_v = []{
    if constexpr(has_member_function_arrow_template_overload_v<T>)
        return is_class_or_union_v<std::remove_pointer_t<member_function_arrow_template_ret_t<T>>>;
    else
        return false;
}();

DEF_CONCEPT has_arrowable_v = has_builtin_arrow_overload_v<T> || has_member_function_arrow_overload_v<T> || has_member_function_arrow_template_overload_v<T>;
DEF_CONCEPT has_nothrow_arrowable_v = []{
    if constexpr     (has_builtin_arrow_overload_v<T>)
        return true;
    else if constexpr(has_member_function_arrow_overload_v<T>)
        return is_nonthrow_function_v<member_function_arrow_overload_t<T>>;
    else if constexpr(has_member_function_arrow_template_overload_v<T>)
        return is_nonthrow_function_v<member_function_arrow_template_overload_t<T>>;
    else
        return false;
}();

DEF_CONCEPT is_arrowable_v = is_builtin_arrowable_v<T> || is_member_function_arrowable_v<T> || is_member_function_template_arrowable_v<T>;
DEF_CONCEPT is_nothrow_arrowable_v = []{
    if constexpr     (is_builtin_arrowable_v<T>)
        return true;
    else if constexpr(is_member_function_arrowable_v<T>)
        return is_nonthrow_function_v<member_function_arrow_overload_t<T>>;
    else if constexpr(is_member_function_template_arrowable_v<T>)
        return is_nonthrow_function_v<member_function_arrow_template_overload_t<T>>;
    else
        return false;
}();

# undef DEF_CONCEPT

template <class T, class = enable_if_t<has_arrowable_v<T>>> using has_arrowable_t = T;
template <class T, class = enable_if_t<has_nothrow_arrowable_v<T>>> using has_nothrow_arrowable_t = T;
DEF_UN_CHECK_T(arrow);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
