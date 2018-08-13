#ifndef __nobodyxu_concept_check_concepts_operations_is_comparable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_comparable_v_HPP__

# include "def_convenient_macros.hpp"

namespace nxwheels {
DEF_BIN_IMP_CONVERT_CHECK(EqualityCompare, ==, bool);
DEF_BIN_IMP_CONVERT_CHECK(InEqualityCompare, !=, bool);
DEF_BIN_IMP_CONVERT_CHECK(LessThanCompare, <, bool);
DEF_BIN_IMP_CONVERT_CHECK(LessEqualCompare, <=, bool);
DEF_BIN_IMP_CONVERT_CHECK(GreaterThanCompare, >, bool);
DEF_BIN_IMP_CONVERT_CHECK(GreaterEqualCompare, >=, bool);

DEF_BIN_CHECK_T(EqualityCompare);
DEF_BIN_CHECK_T(InEqualityCompare);
DEF_BIN_CHECK_T(LessThanCompare);
DEF_BIN_CHECK_T(LessEqualCompare);
DEF_BIN_CHECK_T(GreaterThanCompare);
DEF_BIN_CHECK_T(GreaterEqualCompare);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
