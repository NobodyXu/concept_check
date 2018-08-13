#ifndef __nobodyxu_concept_check_concepts_operations_is_subscriptable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_subscriptable_v_HPP__

# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class T, class Val> using subscripted_t = decltype( declval<T>()[declval<Val>()] );

template <class T, class Val> constexpr const static inline bool is_subscriptable_v = is_detected_v<subscripted_t, T, Val>;

template <class T, class Val> constexpr const static inline bool _is_nothrow_subscriptable_v = noexcept( declval<T>()[declval<Val>()] );
template <class T, class Val> constexpr const static inline bool is_nothrow_subscriptable_v = []{
    if constexpr(is_subscriptable_v<T, Val>)
        return _is_nothrow_subscriptable_v<T, Val>;
    else
        return false;
}();

DEF_BIN_CHECK_T(subscript);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
