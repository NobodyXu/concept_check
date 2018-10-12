#ifndef  __nobodyxu_concept_check_is_mutable_ref_HPP__
# define __nobodyxu_concept_check_is_mutable_ref_HPP__

# include "../bool_constant.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class T> struct is_mutable_ref: false_type {};

template <class T> struct is_mutable_ref<const T&>: false_type {};
template <class T> struct is_mutable_ref<const T&&>: false_type {};

template <class T> struct is_mutable_ref<T&&>: true_type {};
template <class T> struct is_mutable_ref<T&>: true_type {};

template <class T> CONCEPT_T is_mutable_ref_v = is_mutable_ref<T>::value;
} /* nxwheels */
# include "undef_convenient_macros.hpp"
#endif
