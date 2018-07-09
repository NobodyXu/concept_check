#ifndef __nobodyxu_concept_check_concepts_is_primitive_pointer_HPP__
# define __nobodyxu_concept_check_concepts_is_primitive_pointer_HPP__

# include "../integral_constant.hpp"

namespace nxwheels {
template <class T>          struct is_primitive_pointer:         false_type {};
template <class T>          struct is_primitive_pointer<T*>:     true_type {};
template <class P, class T> struct is_primitive_pointer<P T::*>: true_type {};

template <class T> constexpr const static inline bool is_primitive_pointer_v = is_primitive_pointer<T>::value;
} /* nxwheels */
#endif
