/*!
* In order to use specialization for initializer_list so that the concepts will work correctly, you need to define NOBODYXU_CONCEPT_INCLUDE_INITIALIZER_LIST.
*/
#ifndef __nobodyxu_concept_check_concepts_type_properties_operations_is_trivially_constructible_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_operations_is_trivially_constructible_HPP__

# include "../../../integral_constant.hpp"
# include "../../../control_flow.hpp"
# include "../../is_aggregate_v.hpp"
# include "../../is_class_or_union_v.hpp"

namespace nxwheels::concept_check {
template <class T> constexpr const static inline bool is_trivially_copy_constructible_v    = __has_trivial_copy(T);
template <class T> constexpr const static inline bool is_trivially_default_constructible_v = __has_trivial_constructor(T);

/*!
 * @ tparm T T should be a non-reference type.
 */
template <class T, class ...Args> struct is_trivially_direct_constructible:                           bool_constant<__is_trivially_constructible(T, Args...)> {};
template <class T>                struct is_trivially_direct_constructible<T>:                        bool_constant<is_trivially_default_constructible_v<T>> {};
template <class T, class ...Args> constexpr const static inline bool is_trivially_direct_constructible_v = is_trivially_direct_constructible<T, Args...>::value;
} /* nxwheels::concept_check */
#endif
