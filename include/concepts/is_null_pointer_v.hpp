#ifndef __nobodyxu_concept_check_concepts_is_null_pointer_HPP__
# define __nobodyxu_concept_check_concepts_is_null_pointer_HPP__

namespace nxwheels {
template <class T> constexpr const static inline bool is_null_pointer_v = false;
template <>        constexpr const static inline bool is_null_pointer_v<decltype(nullptr)> = true;
} /* nxwheels */
#endif
