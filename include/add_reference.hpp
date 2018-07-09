#ifndef __nobodyxu_concept_check_add_reference_HPP__
# define __nobodyxu_concept_check_add_reference_HPP__

# include "function_traits.hpp"

namespace nxwheels {
template <class T, bool = is_function_cvref_qualified_v<T>> struct add_lvalue_reference            { using type = T&; };
template <class T>                                          struct add_lvalue_reference<T&, false> { using type = T&; };
template <class T>                                          struct add_lvalue_reference<T, true>   { using type = T; };
template <class T> using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

template <class T, bool = is_function_cvref_qualified_v<T>> struct add_rvalue_reference          { using type = T&&; };
template <class T>                                          struct add_rvalue_reference<T, true> { using type = T; };
template <class T> using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;
} /* nxwheels */
#endif
