#ifndef __nobodyxu_concept_check_type_identity_HPP__
# define __nobodyxu_concept_check_type_identity_HPP__
namespace nxwheels::concept_check {
template <class T> struct type_identity { using type = T; };

template <class T> using type_identity_t = typename type_identity<T>::type;
} /* nxwheels::concept_check */
#endif
