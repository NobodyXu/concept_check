#ifndef __nobodyxu_concept_check_concepts_type_properties_operations_has_virtual_destructor_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_operations_has_virtual_destructor_v_HPP__

namespace nxwheels::concept_check {
template <class T> constexpr const static inline bool has_virtual_destuctor_v = __has_virtual_destructor(T);
} /* nxwheels::concept_check */
#endif
