#ifndef __nobodyxu_concept_check_concepts_type_properties_is_referenceable_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_is_referenceable_v_HPP__

# include "../detector_core.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
TP1 using lvalue_ref_t = T&;
/*!
 * is_referenceable_v tests whether T& is valid.
 */
TP1 CONCEPT_T is_referenceable_v = is_detected_v<lvalue_ref_t, T>;
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
