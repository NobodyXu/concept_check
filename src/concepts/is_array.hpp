#ifndef __nobodyxu_concept_check_concepts_is_array_HPP__
# define __nobodyxu_concept_check_concepts_is_array_HPP__
# include "../integral_constant.hpp"
# include "../usefull_types.hpp"
namespace nxwheels::concept_check {
template <class T>
struct is_array: false_type {};
template <class T>
struct is_array<T[]>: true_type {};
template <class T, size_t N>
struct is_array<T[N]>: true_type {};

template <class T>
constexpr const static inline bool is_array_v = is_array<T>::value;
} /* nxwheels::concept_check */
#endif
