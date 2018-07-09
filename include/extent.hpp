#ifndef __nobodyxu_concept_check_extent_HPP__
# define __nobodyxu_concept_check_extent_HPP__

# include "detector_core.hpp"
# include "usefull_types.hpp"

namespace nxwheels {
template <class T> using member_var_extent_t = decltype(T::extent);

template <class T> constexpr const static inline bool has_member_variable_extent_v = is_detected_v<member_var_extent_t, T>;

/*!
 * Class template extent is always promised to have member variable size_t value.
 * In the default version value == 0;
 * The specilization for which has_member_variable_rank_v is true, value == T::extent;
 * The specilization when T is an unbounded array, value == 0;
 * Specilization for C++ built-in array type is also provided.
 */
template <class T, bool = has_member_variable_extent_v<T>> struct extent              { constexpr const static inline size_t value{0}; };
template <class T>                                         struct extent<T, true>     { constexpr const static inline size_t value = T::extent; };
template <class T>                                         struct extent<T[], false>  { constexpr const static inline size_t value{0}; };
template <class T, size_t N>                               struct extent<T[N], false> { constexpr const static inline size_t value = N; };

template <class T> constexpr const static inline auto extent_v = extent<T>::value;
} /* nxwheels */
#endif
