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
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
