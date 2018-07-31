#ifndef __nobodyxu_concept_check_concepts_type_properties_operations_is_EqualityComparable_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_operations_is_EqualityComparable_v_HPP__

# include "../../../detector_v.hpp"
# include "../../../utility.hpp"

namespace nxwheels {
template <class T1, class T2> using EqualityCompared_t = decltype( declval<T1>() == declval<T2>() );
template <class T1, class T2> using InEqualityCompared_t = decltype( declval<T1>() != declval<T2>() );

template <class T1, class T2 = T1> constexpr const static inline bool _is_EqualityComparable_v = is_detected_implicitly_convertible_v<bool, EqualityCompared_t, T1, T2>;
template <class T1, class T2 = T1> constexpr const static inline bool is_EqualityComparable_v = _is_EqualityComparable_v<T1, T2> && _is_EqualityComparable_v<T2, T1>;

template <class T1, class T2 = T1>
constexpr const static inline bool _is_InEqualityComparable_v = is_detected_implicitly_convertible_v<bool, InEqualityCompared_t, T1, T2>;
template <class T1, class T2 = T1>
constexpr const static inline bool is_InEqualityComparable_v = _is_InEqualityComparable_v<T1, T2> && _is_InEqualityComparable_v<T2, T1>;

template <class T1, class T2 = T1>
constexpr const static inline bool _is_nothrow_EqualityComparable_v = noexcept( declval<T1>() == declval<T2>() ) && noexcept( declval<T2>() == declval<T1>() );
template <class T1, class T2 = T1>
constexpr const static inline bool _is_nothrow_InEqualityComparable_v = noexcept( declval<T1>() != declval<T2>() ) && noexcept( declval<T2>() != declval<T1>() );

template <class T1, class T2 = T1> constexpr const static inline bool is_nothrow_EqualityComparable_v = []{
    if constexpr(is_EqualityComparable_v<T1, T2>)
        return _is_nothrow_EqualityComparable_v<T1, T2>;
    else
        return false;
}();
template <class T1, class T2 = T1> constexpr const static inline bool is_nothrow_InEqualityComparable_v = []{
    if constexpr(is_InEqualityComparable_v<T1, T2>)
        return _is_nothrow_InEqualityComparable_v<T1, T2>;
    else
        return false;
}();
} /* nxwheels */
#endif
