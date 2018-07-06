#ifndef __nobodyxu_concept_check_concepts_type_properties_operations_is_assignable_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_operations_is_assignable_v_HPP__

# include "../../../detector_v.hpp"
# include "../../../utility.hpp"

namespace nxwheels::concept_check::is_assignable_impl {
template <class T1, class T2> using assign = decltype( declval<T1>() = declval<T2>() );
} /* nxwheels::concept_check::is_assignable_impl */

namespace nxwheels::concept_check {
/*!
 * has_assignment_v tests whether t1 (of type T1) = t2 (of type T2) is valid.
 */
template <class T1, class T2> constexpr const static inline bool has_assignment_v = is_detected_v<is_assignable_impl::assign, T1, T2>;
template <class T1, class T2> constexpr const static inline bool has_nothrow_assignment_impl_v = noexcept( declval<T1>() = declval<T2>() );
template <class T1, class T2> constexpr const static inline bool has_nothrow_assignment_v = []{
    if constexpr(has_assignment_v<T1, T2>)
        return has_nothrow_assignment_impl_v<T1, T2>;
    else
        return false;
}();

template <class T1, class T2> constexpr const static inline bool is_std_conformant_assignable_v = is_detected_exact_v<T1&, is_assignable_impl::assign, T1, T2>;
template <class T1, class T2> constexpr const static inline bool is_nothrow_std_conformant_assignable_v = []{
    if constexpr(is_std_conformant_assignable_v<T1, T2>)
        return has_nothrow_assignment_impl_v<T1, T2>;
    else
        return false;
}();
} /* nxwheels::concept_check */
#endif
