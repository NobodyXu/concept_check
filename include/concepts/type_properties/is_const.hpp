#ifndef __nobodyxu_concept_check_concepts_type_properties_is_const_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_is_const_HPP__

# include "../../integral_constant.hpp"

namespace nxwheels {
template <class T> struct is_const:          false_type {};
template <class T> struct is_const<const T>: true_type  {};

template <class T> constexpr const static inline bool is_const_v = is_const<T>::value;
} /* nxwheels */
#endif
