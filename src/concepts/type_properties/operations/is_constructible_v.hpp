#ifndef __nobodyxu_concept_check_is_constructible_v_HPP__
# define __nobodyxu_concept_check_is_constructible_v_HPP__

# include <new>
# include "../../../utility.hpp"
# include "../../../detector_core.hpp"

namespace nxwheels::concept_check::is_ctible_impl {
template <class T, class ...Args> using direct_construct = decltype( new T(declval<Args>()...) );
template <class T, class ...Args> using list_construct = decltype( new T{declval<Args>()...} );
} /* nxwheels::concept_check::is_ctible_impl */

namespace nxwheels::concept_check {
template <class T, class ...Args> constexpr const static inline bool is_direct_constructible_v = is_detected_v<is_ctible_impl::direct_construct, T, Args...>;

template <class T, class ...Args> constexpr const static inline bool is_nothrow_direct_constructible_impl_v = noexcept( new (nullptr) T(declval<Args>()...) );
template <class T, class ...Args> constexpr const static inline bool is_nothrow_direct_constructible_v = [] {
    if constexpr(is_direct_constructible_v<T, Args...>)
        return is_nothrow_direct_constructible_impl_v<T, Args...>;
    else
        return false;
}();

template <class T, class ...Args> constexpr const static inline bool is_list_constructible_v = is_detected_v<is_ctible_impl::list_construct, T, Args...>;

template <class T, class ...Args> constexpr const static inline bool is_nothrow_list_constructible_impl_v = noexcept( new (nullptr) T{declval<Args>()...} );
template <class T, class ...Args> constexpr const static inline bool is_nothrow_list_constructible_v = [] {
    if constexpr(is_list_constructible_v<T, Args...>)
        return is_nothrow_list_constructible_impl_v<T, Args...>;
    else
        return false;
}();
} /* nxwheels::concept_check */
#endif
