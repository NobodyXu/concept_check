#ifndef __nobodyxu_concept_check_concepts_operations_is_self_incrementable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_self_incrementable_v_HPP__

# include <type_traits>

# include "../../add_reference.hpp"

# include "def_convenient_macros.hpp"

namespace nxwheels {
DEF_UN_IMP_CONVERT_CHECK(pre_increment, ++, add_lvalue_reference_t<T>);
DEF_UN_IMP_CONVERT_CHECK(post_increment,  , std::remove_reference_t<T>, ++);

template <class T> CONCEPT_T is_self_incrementable_v = is_pre_incrementable_v<T> && is_post_incrementable_v<T>;
template <class T> CONCEPT_T is_nothrow_self_incrementable_v = is_nothrow_pre_incrementable_v<T> && is_nothrow_post_incrementable_v<T>;

DEF_UN_CHECK_T(pre_increment);
DEF_UN_CHECK_T(post_increment);
DEF_UN_CHECK_T(self_increment);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
