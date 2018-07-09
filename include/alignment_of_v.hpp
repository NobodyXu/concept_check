#ifndef __nobodyxu_concept_check_alignment_of_v_HPP__
# define __nobodyxu_concept_check_alignment_of_v_HPP__

namespace nxwheels {
template <class T> constexpr const static inline auto alignment_of_v = alignof(T);
} /* nxwheels */
#endif
