/*!
 * This file is different from operations/is_arithmetic_v.hpp which check whether a type has a specific arithmetic operation.
 * The concept in this file check whether a type is an arithmetic type.
 */
#ifndef __nobodyxu_concept_check_concepts_is_arithmetic_v_HPP__
# define __nobodyxu_concept_check_concepts_is_arithmetic_v_HPP__

# include <type_traits>

# include "../add_reference.hpp"

# include "operations/is_arithmetic_v.hpp"
# include "operations/is_constructible_v.hpp"
# include "operations/is_convertible_v.hpp"
# include "operations/is_self_decrementable_v.hpp"
# include "operations/is_self_incrementable_v.hpp"
# include "operations/is_Swappable_v.hpp"

# include "def_convenient_macros.hpp"

namespace nxwheels {
# define CHECK_OP(NAME) is_nothrow_## NAME ##able_v<T, T> && is_nothrow_## NAME ##_assignmentable_v<add_lvalue_reference_t<T>, add_lvalue_reference_t<T>>
DEF_CONCEPT1 is_arithmetic_v = /* type requirement */
                               std::is_trivial<T>{}() &&
                               /* ctor requirement */
                               is_nothrow_copy_constructible_v   <T> &&
                               is_nothrow_move_constructible_v   <T> &&
                               /* asignment requirement */
                               std::is_nothrow_copy_assignable<T>{}() &&
                               std::is_nothrow_move_assignable<T>{}() &&
                               /* swap requirement */
                               is_nothrow_swappable_v<add_lvalue_reference_t<T>> &&
                               /* convertion requirement */
                               is_implicitly_convertible_v<T, bool> &&
                               /* arithmetic operations requirement */
                               /* Unary ops */
                               is_nothrow_unary_plusable_v<T> &&
                               is_nothrow_unary_minusable_v<T> &&
                               is_nothrow_bitwise_notable_v<T> &&
                               /* Binary ops */
                               CHECK_OP(addition) &&
                               CHECK_OP(subtraction) &&
                               CHECK_OP(multipliction) &&
                               CHECK_OP(division) &&
                               CHECK_OP(modulo) &&
                               CHECK_OP(bitwise_and) &&
                               CHECK_OP(bitwise_or) &&
                               CHECK_OP(bitwise_xor) &&
                               CHECK_OP(bitwise_left_shift) &&
                               CHECK_OP(bitwise_right_shift) &&
                               /* self inc/dec */
                               is_self_incrementable_v<add_lvalue_reference_t<T>> &&
                               is_self_decrementable_v<add_lvalue_reference_t<T>>;
# undef CHECK_OP

DEF_CHECK1(arithmetic);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
