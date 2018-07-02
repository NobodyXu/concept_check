#ifndef __nobodyxu_concept_check_concepts_is_class_or_union_v_HPP__
# define __nobodyxu_concept_check_concepts_is_class_or_union_v_HPP__
# include "../detector_core.hpp"
namespace nxwheels::concept_check::is_class_or_union_impl {
template <class T> using member_pointer_t = int T::*;
} /* nxwheels::concept_check::is_class_or_union_impl */
namespace nxwheels::concept_check {
template <class T> constexpr const static inline bool is_class_or_union_v = is_detected_v<is_class_or_union_impl::member_pointer_t, T>;
} /* nxwheels::concept_check */
#endif
