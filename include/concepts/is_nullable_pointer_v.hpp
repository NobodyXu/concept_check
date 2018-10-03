#ifndef __nobodyxu_concept_check_concepts_is_nullable_pointer_v_HPP__
# define __nobodyxu_concept_check_concepts_is_nullable_pointer_v_HPP__

# include <memory>

# include "is_iterator_core.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
# define TRAITS(MEMBER_NAME) typename std::pointer_traits<T>:: MEMBER_NAME
# define NULLP_T decltype(nullptr)
DEF_CONCEPT1 is_nullable_pointer_v = []{
    if constexpr(
        is_dereferenceable_v<T>                                                        &&
        /* ctor, assign requirement */
        (is_direct_constructible_v<T, NULLP_T> || is_list_constructible_v<T, NULLP_T>) &&
        std::is_assignable<T&, NULLP_T>{}()                                            &&
        /* Comparable with nullptr */
        is_EqualityCompareable_v<T, NULLP_T> && is_InEqualityCompareable_v<T, NULLP_T> &&
        /* Part of Iterator requirement */
        is_RandomAccessIterator_core_impl_comp_req_v<T>                                &&
        is_BidirectionalIterator_core_v<T>
    )
        return is_RandomAccessIterator_core_impl_other_req_v<T, TRAITS(difference_type), TRAITS(element_type)&> &&
               is_implicitly_convertible_dereferenceable_v  <T, TRAITS(element_type)&>;
    else
        return false;
}();
# undef NULLP_T
# undef TRAITS

DEF_CHECK1(nullable_pointer);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
