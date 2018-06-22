#ifndef __nobodyxu_concept_check_add_reference_HPP__
# define __nobodyxu_concept_check_add_reference_HPP__
namespace nxwheels::concept_check {
template <class T>
struct add_lvalue_reference {
    typedef T& type;
};
template <class T>
struct add_lvalue_reference<T&> {
    typedef T& type;
};
template <class T>
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

template <class T>
struct add_rvalue_reference {
    typedef T&& type;
};
template <class T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;
} /* nxwheels::concept_check */
#endif
