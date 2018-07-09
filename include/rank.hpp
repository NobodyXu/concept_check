#ifndef __nobodyxu_concept_check_rank_HPP__
# define __nobodyxu_concept_check_rank_HPP__

# include "detector_core.hpp"
# include "usefull_types.hpp"

namespace nxwheels {
template <class T> using member_var_rank_t = decltype(T::rank);
template <class T> constexpr const static inline bool has_member_variable_rank_v = is_detected_v<member_var_rank_t, T>;

/*!
 * Class template rank is always promised to have member variable size_t value.
 * In the default version value == 0;
 * The specilization for which has_member_variable_rank_v is true, value == T::rank;
 * Specilization for C++ built-in array type is also provided.
 */
template <class T, bool = has_member_variable_rank_v<T>> struct rank { constexpr const static inline size_t value = 0; };
template <class T>                                       struct rank<T, true> { constexpr const static inline size_t value = T::rank; };
template <class T>                                       struct rank<T[], false> { constexpr const static inline size_t value = 1 + rank<T>::value; };
template <class T, size_t N>                             struct rank<T[N], false> { constexpr const static inline size_t value = 1 + rank<T>::value; };

template <class T>
constexpr const static inline auto rank_v = rank<T>::value;
} /* nxwheels */
#endif
