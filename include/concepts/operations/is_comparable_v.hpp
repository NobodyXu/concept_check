#ifndef __nobodyxu_concept_check_concepts_operations_is_comparable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_comparable_v_HPP__

# include "def_convenient_macros.hpp"

namespace nxwheels::impl {
DEF_BIN_IMP_CONVERT_CHECK(EqualityCompare, ==, bool);
DEF_BIN_IMP_CONVERT_CHECK(InEqualityCompare, !=, bool);
DEF_BIN_IMP_CONVERT_CHECK(LessThanCompare, <, bool);
DEF_BIN_IMP_CONVERT_CHECK(LessEqualCompare, <=, bool);
DEF_BIN_IMP_CONVERT_CHECK(GreaterThanCompare, >, bool);
DEF_BIN_IMP_CONVERT_CHECK(GreaterEqualCompare, >=, bool);
} /* nxwheels::impl */

namespace nxwheels {
# define DEF_CHECK(NAME)                                                                                                                                           \
template <class T1, class T2 = T1> constexpr const static inline bool is_## NAME ##able_v = impl::is_## NAME ##able_v<T1, T2> && impl::is_## NAME ##able_v<T2, T1>;\
template <class T1, class T2 = T1> constexpr const static inline bool is_nothrow_## NAME ##able_v = impl::is_nothrow_## NAME ##able_v<T1, T2> && impl::is_nothrow_## NAME ##able_v<T2, T1>

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
