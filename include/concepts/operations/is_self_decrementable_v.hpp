#ifndef __nobodyxu_concept_check_concepts_operations_is_self_decrementable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_self_decrementable_v_HPP__

# include <type_traits>

# include "../../add_reference.hpp"

# include "def_convenient_macros.hpp"

namespace nxwheels {
DEF_UN_IMP_CONVERT_CHECK(pre_decrement, --, add_lvalue_reference_t<T>);

template <class T> using post_decremented_t = decltype( declval<T>()-- );
template <class T> constexpr const static inline bool is_post_decrementable_v = is_detected_implicitly_convertible_v<std::remove_reference_t<T>, post_decremented_t, T>;
template <class T> constexpr const static inline bool _is_nothrow_post_decrementable_v = noexcept( declval<T>()-- );
template <class T> constexpr const static inline bool is_nothrow_post_decrementable_v = []{
    if constexpr(is_post_decrementable_v<T>)
        return _is_nothrow_post_decrementable_v<T>;
    else
        return false;
}();

template <class T> constexpr const static inline bool is_self_decrementable_v = is_pre_decrementable_v<T> && is_post_decrementable_v<T>;
template <class T> constexpr const static inline bool is_nothrow_self_decrementable_v = is_nothrow_pre_decrementable_v<T> && is_nothrow_post_decrementable_v<T>;

DEF_UN_CHECK_T(pre_decrement);
DEF_UN_CHECK_T(post_decrement);
DEF_UN_CHECK_T(self_decrement);
} /* nxwheels */

# include "def_convenient_macros.hpp"

#endif
