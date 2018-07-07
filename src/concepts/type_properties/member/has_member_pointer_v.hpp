#ifndef __nobodyxu_concept_check_concepts_type_properties_member_has_member_pointer_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_member_has_member_pointer_v_HPP__

# include "../../../detector_core.hpp"

namespace nxwheels::concept_check {
template <class T, class pointed_t = int> using member_pointer_t = pointed_t T::*;

template <class T> constexpr const static inline bool has_member_pointer_v = is_detected_v<member_pointer_t, T>;
} /* nxwheels::concept_check */
#endif
