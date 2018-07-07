#ifndef __nobodyxu_concept_check_concepts_type_properties_is_pointable_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_is_pointable_v_HPP__

# include "../../detector_core.hpp"

namespace nxwheels::concept_check::is_point_impl {
template <class T> using p_t = T*;
} /* nxwheels::concept_check::is_point_impl */

namespace nxwheels::concept_check {
template <class T> constexpr const static inline bool is_pointable_v = is_detected_v<is_point_impl::p_t, T>;
} /* nxwheels::concept_check */
#endif
