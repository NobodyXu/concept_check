#ifndef __nobodyxu_concept_check_concepts_is_builtin_nonmember_pointer_HPP__
# define __nobodyxu_concept_check_concepts_is_builtin_nonmember_pointer_HPP__

# include "../bool_constant.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class T> struct is_builtin_nonmember_pointer:     false_type {};
template <class T> struct is_builtin_nonmember_pointer<T*>: true_type {};

DEF_CONCEPT1 is_builtin_nonmember_pointer_v = is_builtin_nonmember_pointer<T>::value;
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
