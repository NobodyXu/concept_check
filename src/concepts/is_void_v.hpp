#ifndef __nobodyxu_concept_check_concepts_is_void_v_HPP__
# define __nobodyxu_concept_check_concepts_is_void_v_HPP__
# include "../integral_constant.hpp"
namespace nxwheels::concept_check {
template <class T> constexpr const static inline bool is_void_v       = false;
template <>        constexpr const static inline bool is_void_v<void> = true;
} /* nxwheels::concept_check */
#endif
