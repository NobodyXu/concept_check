#ifndef __nobodyxu_concept_check_remove_cv_HPP__
# define __nobodyxu_concept_check_remove_cv_HPP__

namespace nxwheels::concept_check {
template <class T> struct remove_const          { typedef T type; };
template <class T> struct remove_const<const T> { typedef T type; };
template <class T> using remove_const_t = typename remove_const<T>::type;

template <class T> struct remove_volatile             { typedef T type; };
template <class T> struct remove_volatile<volatile T> { typedef T type; };
template <class T> using remove_volatile_t = typename remove_volatile<T>::type;

template <class T> using remove_cv_t = remove_const_t<remove_volatile_t<T>>;
template <class T> struct remove_cv { typedef remove_cv_t<T> type; };
} /* nxwheels::concept_check */
#endif
