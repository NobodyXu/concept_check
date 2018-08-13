#ifndef __nobodxu_concept_check_concepts_operations_is_arrowable_v_HPP__
# define __nobodxu_concept_check_concepts_operations_is_arrowable_v_HPP__

# include "../../detector_core.hpp"
# include "../../function_traits.hpp"
# include "../../bool_constant.hpp"
# include "../is_class_or_union_v.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class T> struct is_builtin_arrowable:     false_type {};
template <class T> struct is_builtin_arrowable<T*>: bool_constant<is_class_or_union_v<T>> {};
template <class T> constexpr const static inline bool is_builtin_arrowable_v = is_builtin_arrowable<T>::value;

template <class T> using member_function_arrow_overload_t          = decltype(&T::operator ->);
template <class T> using member_function_arrow_template_overload_t = decltype(&T::template operator -> <>);

template <class T> constexpr const static inline bool has_member_function_arrow_overload_v          = is_detected_v<member_function_arrow_overload_t, T>;
template <class T> constexpr const static inline bool has_member_function_arrow_template_overload_v = is_detected_v<member_function_arrow_template_overload_t, T>;

template <class T>
constexpr const static inline bool is_arrowable_v = is_builtin_arrowable_v<T> || has_member_function_arrow_overload_v<T> || has_member_function_arrow_template_overload_v<T>;

template <class T> constexpr const static inline bool is_nothrow_arrowable_v = []{
    if constexpr     (is_builtin_arrowable_v<T>)
        return true;
    else if constexpr(has_member_function_arrow_overload_v<T>)
        return is_nonthrow_function_v<member_function_arrow_overload_t<T>>;
    else if constexpr(has_member_function_arrow_template_overload_v<T>)
        return is_nonthrow_function_v<member_function_arrow_template_overload_t<T>>;
    else
        return false;
}();

DEF_UN_CHECK_T(arrow);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
