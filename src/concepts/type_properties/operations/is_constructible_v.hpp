#ifndef __nobodyxu_concept_check_is_constructible_v_HPP__
# define __nobodyxu_concept_check_is_constructible_v_HPP__

# include <new>
# include "../../../utility.hpp"
# include "../../../detector_core.hpp"

namespace nxwheels::concept_check {
template <class T, class ...Args> using direct_construct_t          = decltype( new T(declval<Args>()...) );
template <class T, class ...Args> using list_construct_t            = decltype( new T{declval<Args>()...} );
template <class T, class ...Args> using initialier_list_construct_t = decltype( new T({declval<Args>()...}) );

/*!
 * Test whether new T(declval<Args>()...) is valid.
 */
template <class T, class ...Args> constexpr const static inline bool is_direct_constructible_v = is_detected_v<direct_construct_t, T, Args...>;
/*!
 * Test whether new T(declval<Args>()...) is valid and new (nullptr) T(declval<Args>()...) is noexcept.
 */
template <class T, class ...Args> constexpr const static inline bool is_nothrow_direct_constructible_impl_v = noexcept( new (nullptr) T(declval<Args>()...) );
template <class T, class ...Args> constexpr const static inline bool is_nothrow_direct_constructible_v = [] {
    if constexpr(is_direct_constructible_v<T, Args...>)
        return is_nothrow_direct_constructible_impl_v<T, Args...>;
    else
        return false;
}();

/*!
 * Test whether new T{declval<Args>()...} is valid.
 */
template <class T, class ...Args> constexpr const static inline bool is_list_constructible_v = is_detected_v<list_construct_t, T, Args...>;
/*!
 * Test whether new T{declval<Args>()...} is valid and new (nullptr) T{declval<Args>()...} is noexcept.
 */
template <class T, class ...Args> constexpr const static inline bool is_nothrow_list_constructible_impl_v = noexcept( new (nullptr) T{declval<Args>()...} );
template <class T, class ...Args> constexpr const static inline bool is_nothrow_list_constructible_v = [] {
    if constexpr(is_list_constructible_v<T, Args...>)
        return is_nothrow_list_constructible_impl_v<T, Args...>;
    else
        return false;
}();

/*!
 * Test whether new T({declval<Args>()...}) is valid.
 */
template <class T, class ...Args> constexpr const static inline bool is_initializer_list_constructible_v = is_detected_v<initialier_list_construct_t, T, Args...>;
/*!
 * Test whether new T({declval<Args>()...}) is valid and new (nullptr) T({declval<Args>()...}) is noexcept.
 */
template <class T, class ...Args> constexpr const static inline bool is_nothrow_initializer_list_constructible_impl_v = noexcept( new (nullptr) T({declval<Args>()...}) );
template <class T, class ...Args> constexpr const static inline bool is_nothrow_initializer_list_constructible_v = []{
    if constexpr(is_initializer_list_constructible_v<T, Args...>)
        return is_nothrow_initializer_list_constructible_impl_v<T, Args...>;
    else
        return false;
}();
} /* nxwheels::concept_check */
#endif
