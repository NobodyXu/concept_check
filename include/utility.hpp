#ifndef __nobodyxu_concept_check_utility_HPP__
# define __nobodyxu_concept_check_utility_HPP__

# include "add_reference.hpp"

namespace nxwheels {
template <class T> using as = T;

/*!
 * declval can be only used in unevaluated context.
 */
template <class T> auto declval() noexcept -> add_rvalue_reference_t<T>;
/*!
 * declval can be only used in unevaluated context.
 */
template <class T> auto decl_as() noexcept -> T;
} /* nxwheels */
#endif
