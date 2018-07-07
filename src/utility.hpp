#ifndef __nobodyxu_concept_check_declval_HPP__
# define __nobodyxu_concept_check_declval_HPP__

# include "add_reference.hpp"

namespace nxwheels::concept_check {
template <class T> using as = T;

/*!
 * declval can be only used in unevaluated context.
 */
template <class T> auto declval() noexcept -> add_rvalue_reference_t<T>;
/*!
 * declval can be only used in unevaluated context.
 */
template <class T> auto decl_as() noexcept -> T;
} /* nxwheels::concept_check */
#endif
