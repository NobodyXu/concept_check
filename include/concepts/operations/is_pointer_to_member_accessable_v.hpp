#ifndef __nobodyxu_concept_check_concepts_type_properties_operations_is_pointer_to_member_accessable_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_operations_is_pointer_to_member_accessable_v_HPP__

# include "../../../detector_core.hpp"
# include "../../../integral_constant.hpp"
# include "../../../partial_apply.hpp"
# include "../../../utility.hpp"

# include "../../is_member_pointer.hpp"

namespace nxwheels {
// Beg of impl of is_pointer_to_member_accessable_v.
template <class T, class P> using pointer_to_data_member_accessed_t = decltype( declval<T>()->*declval<P>() );
/*!
 * Test whether declval<T>()->*declval<P>() is valid.
 */
template <class T, class P> constexpr const static inline bool is_pointer_to_data_member_accessable_v = is_detected_v<pointer_to_data_member_accessed_t, T, P>;
// End of impl of is_pointer_to_member_accessable_v.

// Beg of impl of is_pointer_to_function_member_accessable_v.
template <class T, class P, class ...Args> using pointer_to_function_member_accessed_t = decltype( (declval<T>()->*declval<P>())(declval<Args>()...) );
/*!
 * Test whether (declval<T>()->*declval<P>())(declval<Args>()...) is valid.
 * This is the implementation for _is_pointer_to_function_member_accessable_v.
 */
template <class T, class P, class ...Args>
constexpr const static inline bool __is_pointer_to_function_member_accessable_v = is_detected_v<pointer_to_function_member_accessed_t, T, P, Args...>;
/*!
 * Class wrapper for _is_pointer_to_function_member_accessable_v so that it can be passed as a class template.
 */
template <class T, class P, class ...Args> struct __is_pointer_to_function_member_accessable: bool_constant<__is_pointer_to_function_member_accessable_v<T, P, Args...>> {};
/*!
 * Implementation of is_pointer_to_function_member_accessable_v.
 * _is_pointer_to_function_member_accessable_v assumes template parameter P is a function pointer type.
 */
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
// End of impl of is_pointer_to_function_member_accessable_v.

// Beg of impl of _is_nothrow_pointer_to_data_member_accessable_v and _is_nothrow_pointer_to_function_member_accessable_v.
template <class T, class P> constexpr const static inline bool _is_nothrow_pointer_to_data_member_accessable_v = noexcept( declval<T>()->*declval<P>() );
template <class T, class P, class ...Args>
constexpr const static inline bool __is_nothrow_pointer_to_function_member_accessable_v = noexcept( (declval<T>()->*declval<P>())(declval<Args>()...) );
template <class T, class P, class ...Args>
struct __is_nothrow_pointer_to_function_member_accessable: bool_constant<__is_nothrow_pointer_to_function_member_accessable_v<T, P, Args...>> {};
// End of impl of _is_nothrow_pointer_to_data_member_accessable_v and _is_nothrow_pointer_to_function_member_accessable_v.

// Beg of impl of is_nothrow_pointer_to_data_member_accessable_v and is_nothrow_pointer_to_function_member_accessable_v.
template <class T, class P> constexpr const static inline bool is_nothrow_pointer_to_data_member_accessable_v = []{
    if constexpr(is_pointer_to_data_member_accessable_v<T, P>)
        return _is_nothrow_pointer_to_data_member_accessable_v<T, P>;
    else
        return false;
}();
/*!
 * _is_nothrow_pointer_to_function_member_accessable_v assumes is_member_function_pointer_v<P> == true.
 */
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
// End of impl of is_nothrow_pointer_to_data_member_accessable_v and is_nothrow_pointer_to_function_member_accessable_v.

// Beg of impl of is_pointer_to_member_accessable_v and is_nothrow_pointer_to_member_accessable_v.
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
// End of impl of is_pointer_to_member_accessable_v and is_nothrow_pointer_to_member_accessable_v.
} /* nxwheels */
#endif
