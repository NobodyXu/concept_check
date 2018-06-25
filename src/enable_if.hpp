#ifndef __nobodyxu_concept_check_enable_if_HPP__
# define __nobodyxu_concept_check_enable_if_HPP__
namespace nxwheels::concept_check {
template <bool, class T = void> struct enable_if {};
template <class T>              struct enable_if<true, T> { using type = T; };

template <bool condition, class T = void> using enable_if_t = typename enable_if<condition, T>::type;
} /* nxwheels::concept_check */
#endif
