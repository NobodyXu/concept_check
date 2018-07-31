#ifndef __nobodyxu_concept_check_concepts_type_properties_is_iterator_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_is_iterator_v_HPP__

# include "operations/is_assignable_v.hpp"
# include "operations/is_constructible_v.hpp"
# include "operations/is_dereferenceable_v.hpp"
# include "operations/is_destructible_v.hpp"
# include "operations/is_EqualityComparable_v.hpp"
# include "operations/is_self_incrementable_v.hpp"
# include "operations/is_swappable_v.hpp"

# include "has_valid_iterator_traits_v.hpp"

namespace nxwheels {
template <class T>
constexpr const static inline bool is_iterator_dereferenceable_v = is_detected_implicitly_convertible_v<typename std::iterator_traits<T>::reference, dereferenced_t, T>;
template <class T>
constexpr const static inline bool _is_iterator_v = is_direct_constructible_v                 <T, const T&> &&
                                                    is_std_conformant_assignable_v            <T, T&>       &&
                                                    is_destructible_v                         <T>           &&
                                                    is_swappable_v                            <T&>          &&
                                                    has_valid_iterator_traits_member_type_v   <T>           &&
                                                    is_pre_incrementable_v                    <T&>;
template <class T> constexpr const static inline bool is_iterator_v = _is_iterator_v<T> && is_dereferenceable_v<T&>;
} /* nxwheels */
#endif
