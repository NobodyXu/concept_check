#ifndef __nobodyxu_concept_check_concepts_operations_is_pointer_to_member_accessable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_pointer_to_member_accessable_v_HPP__

# include "def_convenient_macros.hpp"
# include "../is_member_pointer.hpp"

namespace nxwheels {
template <class T, class P> using pointer_to_data_member_accessed_t = decltype( declval<T>()->*declval<P>() );
template <class T, class P> constexpr const static inline bool is_pointer_to_data_member_accessable_v = is_detected_v<pointer_to_data_member_accessed_t, T, P>;

template <class T, class P, class ...Args> using pointer_to_function_member_accessed_t = decltype( (declval<T>()->*declval<P>())(declval<Args>()...) );
template <class T, class P, class ...Args>
constexpr const static inline bool __is_pointer_to_function_member_accessable_v = is_detected_v<pointer_to_function_member_accessed_t, T, P, Args...>;
template <class T, class P, class ...Args> struct __is_pointer_to_function_member_accessable: bool_constant<__is_pointer_to_function_member_accessable_v<T, P, Args...>> {};
template <class T, class P>
constexpr const static inline bool _is_pointer_to_function_member_accessable_v = apply_function_args_to_t<pointed_to_by_member_pointer_t<P>,
                                                                                                          PARTIAL_APPLY_T(__is_pointer_to_function_member_accessable, T, P)>::value;
template <class T, class P>
constexpr const static inline bool is_pointer_to_function_member_accessable_v = []{
    if constexpr(is_member_function_pointer_v<P>)
        return _is_pointer_to_function_member_accessable_v<T, P>;
    else
        return false;
}();

template <class T, class P> constexpr const static inline bool _is_nothrow_pointer_to_data_member_accessable_v = noexcept( declval<T>()->*declval<P>() );
template <class T, class P, class ...Args>
constexpr const static inline bool __is_nothrow_pointer_to_function_member_accessable_v = noexcept( (declval<T>()->*declval<P>())(declval<Args>()...) );
template <class T, class P, class ...Args>
struct __is_nothrow_pointer_to_function_member_accessable: bool_constant<__is_nothrow_pointer_to_function_member_accessable_v<T, P, Args...>> {};

template <class T, class P> constexpr const static inline bool is_nothrow_pointer_to_data_member_accessable_v = []{
    if constexpr(is_pointer_to_data_member_accessable_v<T, P>)
        return _is_nothrow_pointer_to_data_member_accessable_v<T, P>;
    else
        return false;
}();
template <class T, class P> constexpr const static inline bool _is_nothrow_pointer_to_function_member_accessable_v = []{
    if constexpr(_is_pointer_to_function_member_accessable_v<T, P>)
        return apply_function_args_to_t<pointed_to_by_member_pointer_t<P>, PARTIAL_APPLY_T(__is_nothrow_pointer_to_function_member_accessable, T, P)>::value;
    else
        return false;
}();
template <class T, class P> constexpr const static inline bool is_nothrow_pointer_to_function_member_accessable_v = []{
    if constexpr(is_member_function_pointer_v<P>)
        return _is_nothrow_pointer_to_function_member_accessable_v<T, P>;
    else
        return false;
}();

template <class T, class P> constexpr const static inline bool is_pointer_to_member_accessable_v = []{
    if constexpr(is_member_function_pointer_v<P>)
        return _is_pointer_to_function_member_accessable_v<T, P>;
    else
        return is_pointer_to_data_member_accessable_v<T, P>;
}();
template <class T, class P> constexpr const static inline bool is_nothrow_pointer_to_member_accessable_v = []{
    if constexpr(is_member_function_pointer_v<P>)
        return _is_nothrow_pointer_to_function_member_accessable_v<T, P>;
    else
        return is_nothrow_pointer_to_data_member_accessable_v<T, P>;
}();

DEF_BIN_CHECK_T(pointer_to_member_access);
} /* nxwheels */

# include "def_convenient_macros.hpp"

#endif
