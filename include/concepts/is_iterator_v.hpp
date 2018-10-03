#ifndef __nobodyxu_concept_check_concepts_is_iterator_v_HPP__
# define __nobodyxu_concept_check_concepts_is_iterator_v_HPP__

# include "is_iterator_core.hpp"
# include "has_valid_iterator_traits_v.hpp"

# include "member/has_member_type_value_type_v.hpp"

# include "def_convenient_macros.hpp"

namespace nxwheels {
# define TRAITS(NAME) typename std::iterator_traits<T>:: NAME

DEF_CONCEPT1 is_Iterator_v = is_Iterator_core_v<T> && has_member_type_value_type_v<std::iterator_traits<T>> && is_dereferenceable_v<T>;

DEF_CONCEPT1 is_const_Iterator_v = is_implicitly_convertible_v<TRAITS(reference), const TRAITS(value_type)&>;
DEF_CONCEPT1 is_mutable_Iterator_v = is_implicitly_convertible_v<TRAITS(reference), TRAITS(value_type)&>;

DEF_CONCEPT1 is_InputIterator_impl_v = has_valid_iterator_traits_v<T> && is_exact_dereferenceable_v<T, TRAITS(reference)>;
DEF_CONCEPT1 is_InputIterator_v = is_InputIterator_core_v<T> && is_InputIterator_impl_v<T>;

# define WRAPPER(NAME, TAG)                                                                                                                                       \
DEF_CONCEPT1 is_## NAME ##Iterator_v = is_## NAME ##Iterator_core_v<T> && is_InputIterator_impl_v<T> && std::is_base_of<std:: TAG ##_iterator_tag, TRAITS(iterator_category)>{}();\
DEF_CONCEPT1 is_const_## NAME ##Iterator_v = is_## NAME ##Iterator_v<T> && is_const_Iterator_v<T>;                                                          \
DEF_CONCEPT1 is_mutable_## NAME ##Iterator_v = is_## NAME ##Iterator_v<T> && is_mutable_Iterator_v<T>

WRAPPER(Forward, forward);
WRAPPER(Bidirectional, bidirectional);
WRAPPER(RandomAccess, random_access);

# undef WRAPPER
# undef TRAITS

DEF_CHECK1(Iterator);
DEF_CHECK1(InputIterator);

# define DEF_CHECK_LOCAL(NAME) DEF_CHECK1(NAME ##Iterator); DEF_CHECK1(const_## NAME ##Iterator); DEF_CHECK1(mutable_## NAME ##Iterator)

DEF_CHECK_LOCAL(Forward);
DEF_CHECK_LOCAL(Bidirectional);
DEF_CHECK_LOCAL(RandomAccess);

# undef DEF_CHECK_LOCAL
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
