#ifndef __nobodyxu_concept_check_concepts_is_same_HPP__
# define __nobodyxu_concept_check_concepts_is_same_HPP__

# include "../bool_constant.hpp"

namespace nxwheels {
/*!
 * is_same compares whether all types in Args is the same. If sizeof...(Args) < 2, the value is false.
 */
template <class ...Args> struct is_same: false_type {};

// The loop.
template <class T1, class T2, class ...Args>
struct is_same<T1, T2, Args...>:             bool_constant<is_same<T1, T2>::value             && is_same<T2, Args...>::value> {};
template <class T1, class T2, class T3, class ...Args>
struct is_same<T1, T2, T3, Args...>:         bool_constant<is_same<T1, T2, T3>::value         && is_same<T3, Args...>::value> {};
template <class T1, class T2, class T3, class T4, class ...Args>
struct is_same<T1, T2, T3, T4, Args...>:     bool_constant<is_same<T1, T2, T3, T4>::value     && is_same<T4, Args...>::value> {};
template <class T1, class T2, class T3, class T4, class T5, class ...Args>
struct is_same<T1, T2, T3, T4, T5, Args...>: bool_constant<is_same<T1, T2, T3, T4, T5>::value && is_same<T5, Args...>::value> {};

// The end of loop.
template <class T> struct is_same<T, T>:          true_type {};
template <class T> struct is_same<T, T, T>:       true_type {};
template <class T> struct is_same<T, T, T, T>:    true_type {};
template <class T> struct is_same<T, T, T, T, T>: true_type {};

template <class ...Args> constexpr const static inline bool is_same_v = is_same<Args...>::value;
/*!
 * Its function body contains a static_assert that checks whether is_same_v<Args...> is true.
 */
template <class ...Args> constexpr void assert_same_type() noexcept { static_assert(is_same_v<Args...>, "They are not the same type!"); }
/*!
 * Its function body contains a static_assert that checks whether is_same_v<Args...> is false.
 */
template <class ...Args> constexpr void assert_not_same_type() noexcept { static_assert(!is_same_v<Args...>, "They are the same type!"); }
} /* nxwheels */
#endif
