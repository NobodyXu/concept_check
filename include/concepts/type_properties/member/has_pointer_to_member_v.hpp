#ifndef __nobodyxu_concept_check_concepts_type_properties_member_has_pointer_to_member_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_member_has_pointer_to_member_v_HPP__

# include "../../../detector_core.hpp"

namespace nxwheels {
template <class T, class pointed_t = int> using pointer_to_member_t = pointed_t T::*;

template <class T> constexpr const static inline bool has_pointer_to_member_v = is_detected_v<pointer_to_member_t, T>;
} /* nxwheels */
#endif
