#ifndef __nobodyxu_concept_check_concepts_operations_is_arithmetic_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_arithmetic_v_HPP__

# include "../../add_reference.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
DEF_UN_IMP_CONVERT_CHECK(unary_plus, +, T);
DEF_UN_IMP_CONVERT_CHECK(unary_minus, -, T);
DEF_UN_IMP_CONVERT_CHECK(bitwise_not, ~, T);

#  define DEF_TP2(NAME, OP)\
DEF_BIN_IMP_CONVERT_CHECK(NAME, OP, T1);\
DEF_BIN_IMP_CONVERT_CHECK(NAME ## _assignment, OP##=, add_lvalue_reference_t<T1>)

DEF_TP2(addition, +);
DEF_TP2(subtraction, -);
DEF_TP2(multipliction, *);
DEF_TP2(division, /);
DEF_TP2(modulo, %);
DEF_TP2(bitwise_and, &);
DEF_TP2(bitwise_or, |);
DEF_TP2(bitwise_xor, ^);
DEF_TP2(bitwise_left_shift, <<);
DEF_TP2(bitwise_right_shift, >>);

#  undef DEF_TP2
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
