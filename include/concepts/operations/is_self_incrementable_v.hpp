#ifndef __nobodyxu_concept_check_concepts_operations_is_self_incrementable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_self_incrementable_v_HPP__

# include <type_traits>
# include "../../add_reference.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class T> using pre_incremented_t = decltype( ++declval<T>() );
template <class T> using post_incremented_t = decltype( declval<T>()++ );

/*!
 * is_pre_incrementable_v can not deal with void.
 */
template <class T> constexpr const static inline bool is_pre_incrementable_v  = is_detected_implicitly_convertible_v<add_lvalue_reference_t<T>, pre_incremented_t,  T>;
/*!
 * is_pre_incrementable_v can not deal with void.
 */
template <class T> constexpr const static inline bool is_post_incrementable_v = is_detected_implicitly_convertible_v<std::remove_reference_t<T>, post_incremented_t, T>;

template <class T> constexpr const static inline bool _is_nothrow_pre_incrementable_v  = noexcept( ++declval<T>() );
template <class T> constexpr const static inline bool _is_nothrow_post_incrementable_v = noexcept( declval<T>()++ );

template <class T> constexpr const static inline bool is_nothrow_pre_incrementable_v = [] {
    if constexpr(is_pre_incrementable_v<T>)
        return _is_nothrow_pre_incrementable_v<T>;
    else
        return false;
}();
template <class T> constexpr const static inline bool is_nothrow_post_incrementable_v = [] {
    if constexpr(is_post_incrementable_v<T>)
        return _is_nothrow_post_incrementable_v<T>;
    else
        return false;
}();

DEF_UN_CHECK_T(pre_increment);
DEF_UN_CHECK_T(post_increment);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
