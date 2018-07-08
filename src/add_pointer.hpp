#ifndef __nobodyxu_concept_check_add_pointer_HPP__
# define __nobodyxu_concept_check_add_pointer_HPP__

# include "function_traits.hpp"

namespace nxwheels::concept_check {
template <class T, bool = is_function_v<T>> struct add_pointer       { using type = T*; };
template <class T>                          struct add_pointer<T, 1> { using type = typename function_traits<T>::add_pointer_t; };
template <class T>                          struct add_pointer<T&, 0> { using type = T*; };
template <class T>                          struct add_pointer<T&&, 0> { using type = T*; };

template <class T> using add_pointer_t = typename add_pointer<T>::type;
} /* nxwheels::concept_check */
#endif
