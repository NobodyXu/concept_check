#ifndef __nobodyxu_concept_check_concepts_is_builtin_pointer_HPP__
# define __nobodyxu_concept_check_concepts_is_builtin_pointer_HPP__

# include "is_builtin_nonmember_pointer.hpp"
# include "is_member_pointer.hpp"

namespace nxwheels {
template <class T>
constexpr const static inline bool is_builtin_pointer_v = is_builtin_nonmember_pointer_v<T> || is_member_pointer_v<T>;
} /* nxwheels */
#endif
