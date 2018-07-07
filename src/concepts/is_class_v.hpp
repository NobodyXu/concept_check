#ifndef __nobodyxu_concept_check_concepts_is_class_v_HPP__
# define __nobodyxu_concept_check_concepts_is_class_v_HPP__

namespace nxwheels::concept_check {
template <class T> constexpr const static inline bool is_class_v = __is_class(T);
} /* nxwheels::concept_check */
#endif
