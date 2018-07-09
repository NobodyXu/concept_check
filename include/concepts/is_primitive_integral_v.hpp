#ifndef __nobodyxu_concept_check_concepts_is_primitive_integral_v_HPP__
# define __nobodyxu_concept_check_concepts_is_primitive_integral_v_HPP__

namespace nxwheels {
template <class T> constexpr const static inline bool is_primitive_integral_v = false;

# define DEF_SP(type)\
template <>        constexpr const static inline bool is_primitive_integral_v< type > = true;
# define DEF_SP_INT(type) DEF_SP(unsigned type); DEF_SP(signed type)

DEF_SP_INT(char);
DEF_SP_INT(short int);
DEF_SP_INT(int);
DEF_SP_INT(long int);
DEF_SP_INT(long long int);

# undef DEF_SP_INT
# undef DEF_SP
} /* nxwheels */
#endif
