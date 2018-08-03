#ifndef __nobodyxu_concept_check_concepts_operations_is_self_decrementable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_self_decrementable_v_HPP__

# include <type_traits>
# include "../../add_reference.hpp"
# include "../../detector_v.hpp"
# include "../../utility.hpp"

namespace nxwheels {
template <class T> using pre_decremented_t = decltype( --declval<T>() );
template <class T> using post_decremented_t = decltype( declval<T>()-- );

template <class T> constexpr const static inline bool is_pre_decrementable_v = is_detected_implicitly_convertible_v<add_lvalue_reference_t<T>, pre_decremented_t, T>;
template <class T> constexpr const static inline bool is_post_decrementable_v = is_detected_implicitly_convertible_v<std::remove_reference_t<T>, post_decremented_t, T>;

template <class T> constexpr const static inline bool _is_nothrow_pre_decrementable_v = noexcept( --declval<T>() );
template <class T> constexpr const static inline bool _is_nothrow_post_decrementable_v = noexcept( declval<T>()-- );

template <class T> constexpr const static inline bool is_nothrow_pre_decrementable_v = []{
    if constexpr(is_pre_decrementable_v<T>)
        return _is_nothrow_pre_decrementable_v<T>;
    else
        return false;
}();
template <class T> constexpr const static inline bool is_nothrow_post_decrementable_v = []{
    if constexpr(is_post_decrementable_v<T>)
        return _is_nothrow_post_decrementable_v<T>;
    else
        return false;
}();
} /* nxwheels */
#endif
