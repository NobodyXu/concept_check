#ifndef __nobodyxu_concept_check_remove_reference_HPP__
# define __nobodyxu_concept_check_remove_reference_HPP__

namespace nxwheels {
template <class T> struct remove_reference      { typedef T type; };
template <class T> struct remove_reference<T&>  { typedef T type; };
template <class T> struct remove_reference<T&&> { typedef T type; };

template <class T> using remove_reference_t = typename remove_reference<T>::type;
} /* nxwheels */
#endif
