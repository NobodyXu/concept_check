#ifndef __nobodyxu_concept_check_concepts_is_member_pointer_HPP__
# define __nobodyxu_concept_check_concepts_is_member_pointer_HPP__

# include "../bool_constant.hpp"
# include "../function_traits.hpp"

# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class T>          struct is_member_pointer:         false_type {};
template <class P, class T> struct is_member_pointer<P T::*>: true_type {
    using pointed_t           = P;
    using class_belonged_to_t = T;
};

template <class T>
CONCEPT_T is_member_pointer_v = is_member_pointer<T>::value;
template <class T>
using pointed_to_by_member_pointer_t     = typename is_member_pointer<T>::pointed_t;
template <class T>
using class_member_pointer_belonged_to_t = typename is_member_pointer<T>::class_belonged_to_t;

template <class T>
CONCEPT_T is_member_function_pointer_v = [] {
    if constexpr(is_member_pointer_v<T>)
        return is_function_v<pointed_to_by_member_pointer_t<T>>;
    else
        return false;
}();
template <class T>
CONCEPT_T is_member_object_pointer_v = [] {
    if constexpr(is_member_pointer_v<T>)
        return !is_function_v<pointed_to_by_member_pointer_t<T>>;
    else
        return false;
}();
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
