#ifndef __nobodyxu_concept_check_concepts_operations_has_or_op_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_has_or_op_v_HPP__

# include "../../detector_v.hpp"
# include "../../utility.hpp"

namespace nxwheels {
template <class T1, class T2> using or_op_ret_t = decltype( declval<T1>() || declval<T2>() );
template <class T1, class T2> constexpr const static inline bool has_or_op_v = is_detected_implicitly_convertible_v<bool, or_op_ret_t, T1, T2>;
template <class T1, class T2> constexpr const static inline bool has_nothrow_or_op_impl_v = noexcept( declval<T1>() || declval<T2>() );
template <class T1, class T2> constexpr const static inline bool has_nothrow_or_op_v = []{
    if constexpr(has_or_op_v<T1, T2>)
        return has_nothrow_or_op_impl_v<T1, T2>;
    else
        return false;
}();
} /* nxwheels */
#endif
