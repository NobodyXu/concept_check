#ifndef __nobodyxu_concept_check_concepts_member_has_ntype_type_v_HPP__
# define __nobodyxu_concept_check_concepts_member_has_ntype_type_v_HPP__

# include "../../detector_core.hpp"

namespace nxwheels {
template <class T> using ntype_type_t = typename T::type;

template <class T> constexpr const static inline bool has_ntype_type_v = is_detected_v<ntype_type_t, T>;
} /* nxwheels */
#endif
