#ifndef __nobodyxu_concept_check_concepts_type_properties_is_pointable_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_is_pointable_v_HPP__

# include "../detector_core.hpp"

namespace nxwheels {
template <class T> using pointer_t = T*;
template <class T> constexpr const static inline bool is_pointable_v = is_detected_v<pointer_t, T>;
} /* nxwheels */
#endif
