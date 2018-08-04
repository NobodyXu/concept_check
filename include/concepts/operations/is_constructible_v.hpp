#ifndef __nobodyxu_concept_check_is_constructible_v_HPP__
# define __nobodyxu_concept_check_is_constructible_v_HPP__

# include <new>
# include "../../utility.hpp"
# include "../../detector_core.hpp"

namespace nxwheels {
# define DEF_TMP template <class T, class ...Args>
# define VAR constexpr const static inline bool

DEF_TMP using direct_construct_t          = decltype( new T(declval<Args>()...) );
DEF_TMP using list_construct_t            = decltype( new T{declval<Args>()...} );
DEF_TMP using initialier_list_construct_t = decltype( new T({declval<Args>()...}) );

DEF_TMP VAR is_direct_constructible_v = is_detected_v<direct_construct_t, T, Args...>;
DEF_TMP VAR is_nothrow_direct_constructible_impl_v = noexcept( new (nullptr) T(declval<Args>()...) );
DEF_TMP VAR is_nothrow_direct_constructible_v = [] {
    if constexpr(is_direct_constructible_v<T, Args...>)
        return is_nothrow_direct_constructible_impl_v<T, Args...>;
    else
        return false;
}();

DEF_TMP VAR is_list_constructible_v = is_detected_v<list_construct_t, T, Args...>;
DEF_TMP VAR is_nothrow_list_constructible_impl_v = noexcept( new (nullptr) T{declval<Args>()...} );
DEF_TMP VAR is_nothrow_list_constructible_v = [] {
    if constexpr(is_list_constructible_v<T, Args...>)
        return is_nothrow_list_constructible_impl_v<T, Args...>;
    else
        return false;
}();

DEF_TMP VAR is_initializer_list_constructible_v = is_detected_v<initialier_list_construct_t, T, Args...>;
DEF_TMP VAR is_nothrow_initializer_list_constructible_impl_v = noexcept( new (nullptr) T({declval<Args>()...}) );
DEF_TMP VAR is_nothrow_initializer_list_constructible_v = []{
    if constexpr(is_initializer_list_constructible_v<T, Args...>)
        return is_nothrow_initializer_list_constructible_impl_v<T, Args...>;
    else
        return false;
}();

# undef VAR
# undef DEF_TMP
} /* nxwheels */
#endif
