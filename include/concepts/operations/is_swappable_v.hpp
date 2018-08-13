#ifndef __nobodyxu_concept_check_concepts_operations_is_swappable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_swappable_v_HPP__

# include "../is_referenceable_v.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class T1, class T2> using swap_ret_t = decltype( swap(declval<T1>(), declval<T2>()) );
template <class T1, class T2> constexpr const static inline bool is_swappable_with_impl_v = is_detected_v<swap_ret_t, T1, T2>;
/*!
 * is_swappable_with_v tests whether in the current context swap(declval<T1>(), declval<T2>()) and swap(declval<T2>(), declval<T1>()) is valid.
 * To test standard-conformant concept swappable, usrs need to #include utility and using std::swap; themselves.
 */
template <class T1, class T2> constexpr const static inline bool is_swappable_with_v = []{
    if constexpr(is_referenceable_v<T1> && is_referenceable_v<T2>)
        return is_swappable_with_impl_v<T1, T2> && is_swappable_with_impl_v<T2, T1>;
    else
        return false;
}();

template <class T1, class T2> constexpr const static inline bool _is_nothrow_swappable_with_impl_v = noexcept( swap(declval<T1>(), declval<T2>()) );
template <class T1, class T2>
constexpr const static inline bool is_nothrow_swappable_with_impl_v = _is_nothrow_swappable_with_impl_v<T1, T2> && _is_nothrow_swappable_with_impl_v<T2, T1>;
/*!
 * is_nothrow_swappable_with_v not only tests whether T1 and T2 is swappable, but it also tests whether their swap is non-throwing.
 */
template <class T1, class T2> constexpr const static inline bool is_nothrow_swappable_with_v = []{
    if constexpr(is_swappable_with_v<T1, T2>)
        return is_nothrow_swappable_with_impl_v<T1, T2>;
    else
        return false;
}();

/*!
 * is_swappable_v<T> == is_swappable_with_v<T, T>
 */
template <class T> constexpr const static inline bool is_swappable_v = []{
    if constexpr(is_referenceable_v<T>)
        return is_swappable_with_impl_v<T, T>;
    else
        return false;
}();
/*!
 * is_nothrow_swappable_v<T> == is_nothrow_swappable_with_v<T, T>
 */
template <class T> constexpr const static inline bool is_nothrow_swappable_v = []{
    if constexpr(is_swappable_v<T>)
        return _is_nothrow_swappable_with_impl_v<T, T>;
    else
        return false;
}();

DEF_UN_CHECK_T(swapp);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
