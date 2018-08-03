#ifndef __nobodyxu_concept_check_concepts_member_has_member_type_pointer_v_HPP__
# define __nobodyxu_concept_check_concepts_member_has_member_type_pointer_v_HPP__

# include "../../detector_core.hpp"

namespace nxwheels {
template <class T> using member_type_pointer_t = typename T::pointer;
template <class T> constexpr const static inline bool has_member_type_pointer_v = is_detected_v<member_type_pointer_t, T>;
} /* nxwheels */
#endif
