#ifndef __nobodyxu_concept_check_concepts_operations_is_trivially_destructible_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_trivially_destructible_v_HPP__

namespace nxwheels {
template <class T> constexpr const static inline bool is_trivially_destructible_v = __has_trivial_destructor(T);
} /* nxwheels */
#endif
