#ifndef __nobodyxu_concept_check_concepts_is_builtin_pointer_HPP__
# define __nobodyxu_concept_check_concepts_is_builtin_pointer_HPP__

# include <type_traits>

# include "is_builtin_nonmember_pointer.hpp"
# include "is_member_pointer.hpp"

# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class T>
CONCEPT_T is_builtin_pointer_v = is_builtin_nonmember_pointer_v<T> || is_member_pointer_v<T>;

template <class T>
struct pointed_to_by_pointer {};
template <class T>
struct pointed_to_by_pointer<T*>     { using type = T; };
template <class P, class T>
struct pointed_to_by_pointer<P T::*> { using type = P; };

template <class T>
using pointed_to_by_pointer_t = typename pointed_to_by_pointer<T>::type;
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
