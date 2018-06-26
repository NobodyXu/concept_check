#ifndef __nobodyxu_concept_check_concepts_is_member_pointer_HPP__
# define __nobodyxu_concept_check_concepts_is_member_pointer_HPP__
# include "../integral_constant.hpp"
namespace nxwheels::concept_check {
template <class T>          struct is_member_pointer:         false_type {};
template <class P, class T> struct is_member_pointer<P T::*>: true_type {
    using pointed_t           = P*;
    using class_belonged_to_t = T;
};

template <class T> constexpr const static inline bool is_member_pointer_v = is_member_pointer<T>::value;
template <class T> using pointed_to_by_member_pointer_t     = typename is_member_pointer<T>::pointed_t;
template <class T> using class_member_pointer_belonged_to_t = typename is_member_pointer<T>::class_belonged_to_t;
} /* nxwheels::concept_check */
#endif
