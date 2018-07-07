#ifndef __nodbodyxu_concept_check_concepts_is_primitive_v_HPP__
# define __nodbodyxu_concept_check_concepts_is_primitive_v_HPP__

# include "is_bool_v.hpp"
# include "is_void_v.hpp"
# include "is_null_pointer_v.hpp"
# include "is_primitive_arithmetic_v.hpp"
# include "is_primitive_pointer.hpp"

namespace nxwheels::concept_check {
template <class T>
constexpr const static inline bool is_primitive_v = is_bool_v<T> || is_void_v<T> || is_null_pointer_v<T> || is_primitive_arithmetic_v<T> || is_primitive_pointer_v<T>;
} /* nxwheels::concept_check */
#endif
