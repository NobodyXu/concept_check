#ifndef __nobodyxu_concept_check_concepts_is_class_or_union_v_HPP__
# define __nobodyxu_concept_check_concepts_is_class_or_union_v_HPP__

# include "../detector_core.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class T, class pointed_t = int> using member_pointer_t = pointed_t T::*;

template <class T> CONCEPT_T is_class_or_union_v = is_detected_v<member_pointer_t, T>;
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
