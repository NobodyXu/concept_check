#ifndef __nobodyxu_concept_check_concepts_type_properties_has_valid_iterator_traits_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_has_valid_iterator_traits_v_HPP__

# include <iterator>

# include "member/has_member_difference_type_v.hpp"
# include "member/has_member_value_type_v.hpp"
# include "member/has_member_type_pointer_v.hpp"
# include "member/has_member_type_reference_v.hpp"
# include "member/has_member_type_iterator_category_v.hpp"
# include "operations/is_convertible_v.hpp"

# include "../is_void_v.hpp"

namespace nxwheels {
template <class T, class it_traits = std::iterator_traits<T>>
constexpr const static inline bool has_valid_iterator_traits_member_type_v = has_member_difference_type_v       <it_traits> &&
                                                                             has_member_value_type_v            <it_traits> &&
                                                                             has_member_type_pointer_v          <it_traits> &&
                                                                             has_member_type_reference_v        <it_traits> &&
                                                                             has_member_type_iterator_category_v<it_traits>;

template <class T, class it_traits = std::iterator_traits<T>, class val = typename it_traits::value_type>
constexpr const static inline bool has_valid_iterator_traits_v = has_valid_iterator_traits_member_type_v<T> &&
                                                                 !is_void_v                 <val> &&
                                                                 is_implicitly_convertible_v<typename it_traits::reference, val> &&
                                                                 is_pointer_v;
} /* nxwheels */
#endif
