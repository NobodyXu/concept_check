#ifndef __nobodyxu_concept_check_is_reference_HPP__
# define __nobodyxu_concept_check_is_reference_HPP__
# include "../integral_constant.hpp"
namespace nxwheels::concept_check {
template <class T>
struct is_reference: false_type {};
template <class T>
struct is_reference<T&>: true_type {};
template <class T>
struct is_reference<T&&>: true_type {};

template <class T>
constexpr const static inline bool is_reference_v = is_reference<T>::value;

template <class T>
struct is_lvalue_reference: false_type {};
template <class T>
struct is_lvalue_reference<T&>: true_type {};

template <class T>
constexpr const static inline bool is_lvalue_reference_v = is_lvalue_reference<T>::value;

template <class T>
struct is_rvalue_reference: false_type {};
template <class T>
struct is_rvalue_reference<T&&>: true_type {};

template <class T>
constexpr const static inline bool is_rvalue_reference_v = is_rvalue_reference<T>::value;
} /* nxwheels::concept_check */
#endif
