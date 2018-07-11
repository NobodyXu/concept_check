#ifndef __nobodyxu_concept_check_concepts_type_properties_signess_check_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_signess_check_v_HPP__

namespace nxwheels {
template <class T> constexpr const static inline bool is_signed_v       = T{-1} < T{0};
template <>        constexpr const static inline bool is_signed_v<bool> = false;

template <class T> constexpr const static inline bool is_unsigned_v = !is_signed_v<T>;
} /* nxwheels */
#endif
