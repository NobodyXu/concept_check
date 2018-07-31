#ifndef __nobodyxu_concept_check_concepts_type_properties_member_has_member_difference_type_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_member_has_member_difference_type_v_HPP__

# include "../../../detector_core.hpp"

namespace nxwheels {
template <class T> using member_difference_type_t = typename T::difference_type;
template <class T> constexpr const static inline bool has_member_difference_type_v = is_detected_v<member_difference_type_t, T>;
} /* nxwheels */
#endif
