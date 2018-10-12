#ifndef  __nobodyxu_concept_check_concepts_is_const_ref_HPP__
# define __nobodyxu_concept_check_concepts_is_const_ref_HPP__

# include "../bool_constant.hpp"

# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class T> struct is_const_ref: false_type {};

template <class T> struct is_const_ref<const T&>: true_type {};
template <class T> struct is_const_ref<const T&&>: true_type {};

template <class T> CONCEPT_T is_const_ref_v = is_const_ref<T>::value;
} /* nxwheels */
# include "undef_convenient_macros.hpp"
#endif
