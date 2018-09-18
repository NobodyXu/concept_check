#ifndef __nobodyxu_concept_check_concepts_type_properties_is_iterator_core_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_is_iterator_core_HPP__

# include <type_traits>
# include <iterator>

# include "operations/is_arithmetic_v.hpp"
# include "operations/is_constructible_v.hpp"
# include "operations/is_dereferenceable_v.hpp"
# include "operations/is_comparable_v.hpp"
# include "operations/is_self_incrementable_v.hpp"
# include "operations/is_self_decrementable_v.hpp"
# include "operations/is_subscriptable_v.hpp"
# include "operations/is_Swappable_v.hpp"

# include "def_convenient_macros.hpp"

namespace nxwheels {
DEF_CONCEPT1 is_Iterator_core_v = is_copy_constructible_v<T>     &&
                                  std::is_copy_assignable<T>{}() &&
                                  std::is_destructible<T>{}()    &&
                                  is_swappable_v<T&>             &&
                                  is_self_incrementable_v<T&>;

DEF_CONCEPT1 is_InputIterator_core_v         = is_Iterator_core_v<T> &&
                                               is_EqualityCompareable_v<T> && is_InEqualityCompareable_v<T>;
DEF_CONCEPT1 is_ForwardIterator_core_v       = is_InputIterator_core_v<T>  && is_default_constructible_v<T>;
DEF_CONCEPT1 is_BidirectionalIterator_core_v = is_ForwardIterator_core_v<T> && is_self_decrementable_v<T&>;

DEF_CONCEPT1 is_RandomAccessIterator_core_impl_comp_req_v = is_GreaterEqualCompareable_v<T>                            &&
                                                            is_GreaterThanCompareable_v<T>                             &&
                                                            is_LessEqualCompareable_v<T>                               &&
                                                            is_LessThanCompareable_v<T>;
template <class T, class diff_t, class ref>
CONCEPT_T is_RandomAccessIterator_core_impl_other_req_v = /* arithmetic op requirement */
                                                          /* arithmetic assignment op */
                                                          is_addition_assignmentable_v<T&, diff_t>                    &&
                                                          is_subtraction_assignmentable_v<T&, diff_t>                 &&
                                                          /* nonassignment op */
                                                          is_additionable_v<T, diff_t>                               &&
                                                          is_implicitly_convertible_v<additioned_ret_t<diff_t, T>, T> &&
                                                          is_subtractionable_v<T, diff_t>                            &&
                                                          is_implicitly_convertible_v<subtractioned_ret_t<T, T>, diff_t> &&
                                                          /* access requirement */
                                                          is_subscriptable_v<T, diff_t>                              &&
                                                          /* convertion requirement */
                                                          is_implicitly_convertible_v<subscripted_t<T, diff_t>, ref>;

# define TRAITS(NAME) typename std::iterator_traits<T>:: NAME
template <class T, class diff_t = TRAITS(difference_type), class ref = TRAITS(reference)>
CONCEPT_T is_RandomAccessIterator_core_v = is_BidirectionalIterator_core_v<T>              &&
                                           is_RandomAccessIterator_core_impl_comp_req_v<T> &&
                                           is_RandomAccessIterator_core_impl_other_req_v<T, diff_t, ref>;
# undef TRAITS
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
