#ifndef __nobodyxu_concept_check_concepts_operations_is_dereferenceable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_dereferenceable_v_HPP__

# include "../is_same.hpp"

# include "is_convertible_v.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
DEF_UN_CHECK(dereference, *);

template <class T> using dereferenced_or_nonsuch_t = detected_or_t<nonsuch, dereferenceed_ret_t, T>;

# define DEF_CONCEPT template <class T, class Ret> CONCEPT_T

DEF_CONCEPT is_exact_dereferenceable_v         = is_same_v<dereferenced_or_nonsuch_t<T>, Ret>;
DEF_CONCEPT is_nothrow_exact_dereferenceable_v = is_nothrow_dereferenceable_v<T> && is_exact_dereferenceable_v<T, Ret>;

DEF_CONCEPT is_implicitly_convertible_dereferenceable_v         = is_implicitly_convertible_v<dereferenced_or_nonsuch_t<T>, Ret>;
DEF_CONCEPT is_nothrow_implicitly_convertible_dereferenceable_v = is_nothrow_dereferenceable_v<T> && is_implicitly_convertible_dereferenceable_v<T, Ret>;

# undef DEF_CONCEPT

DEF_UN_CHECK_T(dereference);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
