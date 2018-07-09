#ifndef __nobodyxu_concept_check_concepts_is_bool_v_HPP__
# define __nobodyxu_concept_check_concepts_is_bool_v_HPP__

namespace nxwheels {
template <class T> constexpr const static inline bool is_bool_v       = false;
template <>        constexpr const static inline bool is_bool_v<bool> = true;
} /* nxwheels */
#endif
