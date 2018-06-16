#ifndef __nobodyxu_concept_check_is_same_HPP__
# define __nobodyxu_concept_check_is_same_HPP__
# include "integral_constant.hpp"
namespace nxwheels::concept_check {
template <class T1, class T2>
struct is_same: false_type {};
template <class T>
struct is_same<T, T>: true_type {};
template <class T1, class T2>
constexpr const static inline bool is_same_v = is_same<T1, T2>::value;
} /* nxwheels::concept_check */
#endif
