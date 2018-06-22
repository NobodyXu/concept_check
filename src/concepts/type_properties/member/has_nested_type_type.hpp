#ifndef __nobodyxu_concept_check_concepts_type_properties_member_has_nested_type_type_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_member_has_nested_type_type_HPP__
# include "../../../detector_core.hpp"
namespace nxwheels::concept_check {
template <class T> using nested_type_type_t = typename T::type;

template <class T>
constexpr const static inline bool has_nested_type_type_v = is_detected_v<nested_type_type_t, T>;
template <class T>
using has_nested_type_type = is_detected<nested_type_type_t, T>;
} /* nxwheels::concept_check */
#endif
