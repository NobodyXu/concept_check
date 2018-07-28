#ifndef __nobodyxu_concept_check_concepts_type_properties_operations_has_not_op_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_operations_has_not_op_v_HPP__

# include "../../../detector_v.hpp"
# include "../../../utility.hpp"

namespace nxwheels {
template <class T> using not_op_ret_t = decltype( !declval<T>() );
template <class T> constexpr const static inline bool has_not_op_v = is_detected_implicitly_convertible_v<bool, not_op_ret_t, T>;
template <class T> constexpr const static inline bool has_nothrow_not_op_impl_v = noexcept( !declval<T>() );
template <class T> constexpr const static inline bool has_nothrow_not_op_v = []{
    if constexpr(has_not_op_v<T>)
        return has_nothrow_not_op_impl_v<T>;
    else
        return false;
}();
} /* nxwheels */
#endif
