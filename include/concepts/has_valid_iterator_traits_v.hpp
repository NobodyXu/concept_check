#ifndef __nobodyxu_concept_check_concepts_type_properties_has_valid_iterator_traits_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_has_valid_iterator_traits_v_HPP__

# include <type_traits>
# include <iterator>

# include "member/has_member_type_value_type_v.hpp"
# include "operations/is_convertible_v.hpp"

# include "is_nullable_pointer_v.hpp"
# include "is_arithmetic_v.hpp"

# include "def_convenient_macros.hpp"

namespace nxwheels {
# define TRAITS(MEMBER_NAME) typename std::iterator_traits<T>:: MEMBER_NAME

template <class T>
CONCEPT_T has_valid_iterator_traits_v = []{
    if constexpr(has_member_type_value_type_v<std::iterator_traits<T>>)
        return !std::is_void              <TRAITS(value_type)>{}()                &&
               is_implicitly_convertible_v<TRAITS(reference), TRAITS(value_type)> &&
               is_nullable_pointer_v      <TRAITS(pointer)>                       &&
               is_arithmetic_v            <TRAITS(difference_type)>               &&
               std::is_base_of            <std::input_iterator_tag, TRAITS(iterator_category)>{}();
    else
        return false;
}();

# undef TRAITS
} /* nxwheels */

# include "undef_convenient_macros.hpp"
#endif
