#ifndef __nobodyxu_concept_check_remove_pointer_t_HPP__
# define __nobodyxu_concept_check_remove_pointer_t_HPP__

namespace nxwheels {
template <class T> struct remove_pointer                    { typedef T type; };
template <class T> struct remove_pointer<T*>                { typedef T type; };
template <class T> struct remove_pointer<T* const>          { typedef T type; };
template <class T> struct remove_pointer<T* volatile>       { typedef T type; };
template <class T> struct remove_pointer<T* const volatile> { typedef T type; };

template <class T> using remove_pointer_t = typename remove_pointer<T>::type;
} /* nxwheels */
#endif
