#ifndef __nobodyxu_concept_check_concepts_type_properties_is_referenceable_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_is_referenceable_v_HPP__

# include "../../detector_core.hpp"

namespace nxwheels::concept_check::is_ref_impl {
template <class T> using ref_t = T&;
} /* nxwheels::concept_check::is_ref_impl */

namespace nxwheels::concept_check {
/*!
 * is_referenceable_v tests whether T& is valid.
 */
template <class T> constexpr const static inline bool is_referenceable_v = is_detected_v<is_ref_impl::ref_t, T>;
} /* nxwheels::concept_check */
#endif
