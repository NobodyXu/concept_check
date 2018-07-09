#ifndef __nobodyxu_concept_check_concepts_is_primitive_arithmetic_v_HPP__
# define __nobodyxu_concept_check_concepts_is_primitive_arithmetic_v_HPP__

# include "is_primitive_char_v.hpp"
# include "is_primitive_integral_v.hpp"
# include "is_primitive_floating_v.hpp"

namespace nxwheels {
template <class T> constexpr const static inline bool is_primitive_arithmetic_v = is_primitive_char_v<T> || is_primitive_integral_v<T> || is_primitive_floating_v<T>;
} /* nxwheels */
#endif
