#ifndef __nobodyxu_concept_check_concepts_is_pointer_HPP__
# define __nobodyxu_concept_check_concepts_is_pointer_HPP__
# include "../integral_constant.hpp"
namespace nxwheels::concept_check {
template <class T>          struct is_pointer:         false_type {};
template <class T>          struct is_pointer<T*>:     true_type {};
template <class P, class T> struct is_pointer<P T::*>: true_type {};

template <class T> constexpr const static inline bool is_pointer_v = is_pointer<T>::value;
} /* nxwheels::concept_check */
#endif
