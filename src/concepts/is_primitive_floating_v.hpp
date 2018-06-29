#ifndef __nobodyxu_concept_check_concepts_is_primitive_floating_v_HPP__
# define __nobodyxu_concept_check_concepts_is_primitive_floating_v_HPP__
namespace nxwheels::concept_check {
template <class T> constexpr const static inline bool is_primitive_floating_v = false;

# define DEF_SP(type)\
template <>        constexpr const static inline bool is_primitive_floating_v< type > = true

DEF_SP(float);
DEF_SP(double);
DEF_SP(long double);

# undef DEF_SP
} /* nxwheels::concept_check */
#endif
