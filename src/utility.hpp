#ifndef __nobodyxu_concept_check_declval_HPP__
# define __nobodyxu_concept_check_declval_HPP__
# include "add_reference.hpp"
# include "add_cv_t.hpp"
# include "remove_reference.hpp"
namespace nxwheels::concept_check {
template <class T>
using as = T;

/*!
 * The following 2 functions can be only used in unevaluated context.
 */
template <class T>
auto declval() noexcept -> add_rvalue_reference_t<T>;
template <class T>
auto decl_as() noexcept -> T;

template <class T>
constexpr T&& forward(remove_reference_t<T> &obj) noexcept {
    return as<T&&>(obj);
}

template <class T>
constexpr decltype(auto) move(T &&t) noexcept {
    return add_rvalue_reference_t<T>(t);
}

template <class T>
constexpr decltype(auto) as_const(T &t) {
    return as<add_const_t<T>&>(t);
}
template <class T>
constexpr decltype(auto) as_const(T &&t) {
    return as<add_const_t<T>&&>(t);
}
} /* nxwheels::concept_check */
#endif
