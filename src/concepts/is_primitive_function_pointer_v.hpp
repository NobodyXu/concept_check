#ifndef __nobodyxu_concept_check_concepts_is_primitive_function_pointer_v_HPP__
# define __nobodyxu_concept_check_concepts_is_primitive_function_pointer_v_HPP__

# include "../function_traits.hpp"
# include "../remove_pointer.hpp"

namespace nxwheels::concept_check {
template <class T> constexpr const static inline bool is_primitive_function_pointer_v = is_function_v<remove_pointer_t<T>>;
} /* nxwheels::concept_check */
#endif
