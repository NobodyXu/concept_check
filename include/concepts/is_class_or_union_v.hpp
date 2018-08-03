#ifndef __nobodyxu_concept_check_concepts_is_class_or_union_v_HPP__
# define __nobodyxu_concept_check_concepts_is_class_or_union_v_HPP__

# include "../detector_core.hpp"

namespace nxwheels {
template <class T, class pointed_t = int> using member_pointer_t = pointed_t T::*;
template <class T> constexpr const static inline bool is_class_or_union_v = is_detected_v<member_pointer_t, T>;
} /* nxwheels */
#endif
