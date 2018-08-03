#ifndef __nobodyxu_concept_check_concepts_operations_is_LessThanComparable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_LessThanComparable_v_HPP__

# include "../../detector_v.hpp"
# include "../../utility.hpp"

namespace nxwheels {
template <class T1, class T2> using LessThanCompared_t = decltype( declval<T1>() < declval<T2>() );

template <class T1, class T2 = T1> constexpr const static inline bool _is_LessThanComparable_v = is_detected_implicitly_convertible_v<bool, LessThanCompared_t, T1, T2>;
template <class T1, class T2 = T1> constexpr const static inline bool is_LessThanComparable_v = _is_LessThanComparable_v<T1, T2> && _is_LessThanComparable_v<T2, T1>;

template <class T1, class T2 = T1>
constexpr const static inline bool _is_nothrow_LessThanComparable_v = noexcept( declval<T1>() < declval<T2>() ) && noexcept( declval<T1>() < declval<T2>() );
template <class T1, class T2 = T1> constexpr const static inline bool is_nothrow_LessThanComparable_v = []{
    if constexpr(is_LessThanComparable_v<T1, T2>)
        return _is_nothrow_LessThanComparable_v<T1, T2>;
    else
        return false;
}();
} /* nxwheels */
#endif
