#ifndef __nobodyxu_concept_check_concepts_is_void_HPP__
# define __nobodyxu_concept_check_concepts_is_void_HPP__
# include "../integral_constant.hpp"
namespace nxwheels::concept_check {
template <class T>
constexpr const static inline bool is_void_v = 0;
template <>
constexpr const static inline bool is_void_v<void> = 1;

template <class T>
using is_void = bool_constant<is_void_v<T>>;
} /* nxwheels::concept_check */
#endif
