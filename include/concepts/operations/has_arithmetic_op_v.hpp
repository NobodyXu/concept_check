#ifndef __nobodyxu_concept_check_concepts_operations_has_arithmetic_op_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_has_arithmetic_op_v_HPP__

# include "../../add_reference.hpp"
# include "../../detector_v.hpp"
# include "../../utility.hpp"

namespace nxwheels {
# define DEF_TP1(NAME, OP)                                                                                                                \
template <class T> using NAME ##_op_ret_t = decltype( OP declval<T>() );                                                                 \
template <class T> constexpr const static inline bool has_## NAME ##_op_v = is_detected_implicitly_convertible_v<T, NAME ##_op_ret_t, T>;\
template <class T> constexpr const static inline bool has_nothrow_## NAME ##_op_impl_v = noexcept( OP declval<T>() );                    \
template <class T> constexpr const static inline bool has_nothrow_## NAME ##_op_v = []{                                                  \
    if constexpr(has_## NAME ##_op_v<T>)                                                                                                 \
        return has_nothrow_## NAME ##_op_impl_v<T>;                                                                                      \
    else                                                                                                                                 \
        return false;                                                                                                                    \
}()

DEF_TP1(unary_plus, +);
DEF_TP1(unary_minus, -);
DEF_TP1(bitwise_not, ~);

# undef DEF_TP1
# define DEF_TP2_impl(NAME, OP, TYPE)                                                                                                                         \
template <class T1, class T2> using NAME ##_op_ret_t = decltype( declval<T1>() OP declval<T2>() );                                                            \
template <class T1, class T2> constexpr const static inline bool has_## NAME ##_op_v = is_detected_implicitly_convertible_v< TYPE , NAME ##_op_ret_t, T1, T2>;\
template <class T1, class T2> constexpr const static inline bool has_nothrow_## NAME ##_op_impl_v = noexcept( declval<T1>() OP declval<T2>() );                 \
template <class T1, class T2> constexpr const static inline bool has_nothrow_## NAME ##_op_v = []{                                                            \
    if constexpr(has_## NAME ##_op_v<T1, T2>)                                                                                                                 \
        return has_nothrow_## NAME ##_op_impl_v<T1, T2>;                                                                                                      \
    else                                                                                                                                                      \
        return false;                                                                                                                                         \
}()
#  define DEF_TP2(NAME, OP)\
DEF_TP2_impl(NAME, OP, T1);\
DEF_TP2_impl(NAME ## _assignment, OP##=, add_lvalue_reference_t<T1>)

DEF_TP2(addition, +);
DEF_TP2(subtraction, -);
DEF_TP2(multipliction, *);
DEF_TP2(division, /);
DEF_TP2(modulo, %);
DEF_TP2(bitwise_and, &);
DEF_TP2(bitwise_or, |);
DEF_TP2(bitwise_xor, ^);
DEF_TP2(bitwise_left_shift, <<);
DEF_TP2(bitwise_right_shift, >>);

#  undef DEF_TP2
# undef DEF_TP2_impl
} /* nxwheels */
#endif
