#ifndef __nobodyxu_concept_check_remove_extent_HPP__
# define __nobodyxu_concept_check_remove_extent_HPP__

# include "usefull_types.hpp"

namespace nxwheels::concept_check {
template <class T>           struct remove_extent       { using type = T; };
template <class T>           struct remove_extent<T[]>  { using type = T; };
template <class T, size_t N> struct remove_extent<T[N]> { using type = T; };

template <class T> using remove_extent_t = typename remove_extent<T>::type;

template <class T>           struct remove_all_extent                  { using type = T; };
template <class T>           struct remove_all_extent<T[]>             { using type = typename remove_all_extent<T>::type; };
template <class T, size_t N> struct remove_all_extent<T[N]>            { using type = typename remove_all_extent<T>::type; };

template <class T> using remove_all_extent_t = typename remove_all_extent<T>::type;
} /* nxwheels::concept_check */
#endif
