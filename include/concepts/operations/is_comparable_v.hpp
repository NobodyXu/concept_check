#ifndef __nobodyxu_concept_check_concepts_operations_is_comparable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_comparable_v_HPP__

# include "def_convenient_macros.hpp"

namespace nxwheels {
DEF_BIN_IMP_CONVERT_CHECK(raw_EqualityCompare, ==, bool);
DEF_BIN_IMP_CONVERT_CHECK(raw_InEqualityCompare, !=, bool);
DEF_BIN_IMP_CONVERT_CHECK(raw_LessThanCompare, <, bool);
DEF_BIN_IMP_CONVERT_CHECK(raw_LessEqualCompare, <=, bool);
DEF_BIN_IMP_CONVERT_CHECK(raw_GreaterThanCompare, >, bool);
DEF_BIN_IMP_CONVERT_CHECK(raw_GreaterEqualCompare, >=, bool);

DEF_BIN_CHECK_T(raw_EqualityCompare);
DEF_BIN_CHECK_T(raw_InEqualityCompare);
DEF_BIN_CHECK_T(raw_LessThanCompare);
DEF_BIN_CHECK_T(raw_LessEqualCompare);
DEF_BIN_CHECK_T(raw_GreaterThanCompare);
DEF_BIN_CHECK_T(raw_GreaterEqualCompare);

# define DEF_CHECK(NAME)                                                                                                              \
template <class T1, class T2 = T1> CONCEPT_T is_## NAME ##able_v = is_raw_## NAME ##able_v<T1, T2> && is_raw_## NAME ##able_v<T2, T1>;\
template <class T1, class T2 = T1> CONCEPT_T is_nothrow_## NAME ##able_v = is_nothrow_raw_## NAME ##able_v<T1, T2> && is_nothrow_raw_## NAME ##able_v<T2, T1>

DEF_CHECK(EqualityCompare);
DEF_CHECK(InEqualityCompare);
DEF_CHECK(LessThanCompare);
DEF_CHECK(LessEqualCompare);
DEF_CHECK(GreaterThanCompare);
DEF_CHECK(GreaterEqualCompare);

# undef DEF_CHECK

DEF_BIN_CHECK_T(EqualityCompare);
DEF_BIN_CHECK_T(InEqualityCompare);
DEF_BIN_CHECK_T(LessThanCompare);
DEF_BIN_CHECK_T(LessEqualCompare);
DEF_BIN_CHECK_T(GreaterThanCompare);
DEF_BIN_CHECK_T(GreaterEqualCompare);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
