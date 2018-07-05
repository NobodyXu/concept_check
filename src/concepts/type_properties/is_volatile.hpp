#ifndef __nobodyxu_concept_check_concepts_type_properties_is_volatile_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_is_volatile_HPP__
# include "../../integral_constant.hpp"
namespace nxwheels::concept_check {
template <class T> struct is_volatile:          false_type {};
template <class T> struct is_volatile<volatile T>: true_type {};

template <class T> constexpr const static inline bool is_volatile_v = is_volatile<T>::value;
} /* nxwheels::concept_check */
#endif
