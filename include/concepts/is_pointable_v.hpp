#ifndef __nobodyxu_concept_check_concepts_type_properties_is_pointable_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_is_pointable_v_HPP__

# include "../detector_core.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
TP1 using pointer_t = T*;
TP1 CONCEPT_T is_pointable_v = is_detected_v<pointer_t, T>;
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
