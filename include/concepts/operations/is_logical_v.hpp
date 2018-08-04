#ifndef __nobodyxu_concept_check_concepts_operations_has_logical_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_has_logical_v_HPP__

# include "def_convenient_macros.hpp"

namespace nxwheels {
DEF_UN_IMP_CONVERT_CHECK(not, !, bool);
DEF_BIN_IMP_CONVERT_CHECK(and, &&, bool);
DEF_BIN_IMP_CONVERT_CHECK(or, ||, bool);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
