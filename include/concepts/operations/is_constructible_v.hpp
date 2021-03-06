#ifndef __nobodyxu_concept_check_is_constructible_v_HPP__
# define __nobodyxu_concept_check_is_constructible_v_HPP__

# include <new>

# include "../../partial_apply.hpp"
# include "../../type_tuple.hpp"
# include "../../bool_constant.hpp"

# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class T, class ...Args>
using direct_construct_t          = decltype( new T(declval<Args>()...) );
template <class T, class ...Args>
using list_construct_t            = decltype( new T{declval<Args>()...} );
/*!
 * This is just a naive emulation of initializer_list initialization.
 * You need to manually filter out the situation when default construct, cp/mv is actually expected.
 */
template <class T, class ...Args>
using initialier_list_construct_t = decltype( new T({declval<Args>()...}) );

template <class T, class ...Args>
CONCEPT_T is_direct_constructible_v = is_detected_v<direct_construct_t, T, Args...>;

template <class T, class ...Args>
CONCEPT_T is_nothrow_direct_constructible_impl_v = noexcept( new (nullptr) T(declval<Args>()...) );
template <class T, class ...Args>
CONCEPT_T is_nothrow_direct_constructible_v = [] {
    if constexpr(is_direct_constructible_v<T, Args...>)
        return is_nothrow_direct_constructible_impl_v<T, Args...>;
    else
        return false;
}();

template <class T, class ...Args>
CONCEPT_T is_list_constructible_v = is_detected_v<list_construct_t, T, Args...>;

template <class T, class ...Args>
CONCEPT_T is_nothrow_list_constructible_impl_v = noexcept( new (nullptr) T{declval<Args>()...} );
template <class T, class ...Args>
CONCEPT_T is_nothrow_list_constructible_v = [] {
    if constexpr(is_list_constructible_v<T, Args...>)
        return is_nothrow_list_constructible_impl_v<T, Args...>;
    else
        return false;
}();

template <class T, class ...Args>
struct is_initializer_list_constructible: bool_constant<is_detected_v<initialier_list_construct_t, T, Args...>> {};

template <class T> struct is_initializer_list_constructible<T>          : false_type {};
template <class T> struct is_initializer_list_constructible<T, const T&>: false_type {};
template <class T> struct is_initializer_list_constructible<T, T&&>     : false_type {};
template <class T> struct is_initializer_list_constructible<T, T>       : false_type {};
template <class T> struct is_initializer_list_constructible<T, T&>      : false_type {};

template <class T, class ...Args>
CONCEPT_T is_initializer_list_constructible_v = is_initializer_list_constructible<T, Args...>::value;

// There is no separate is_nothrow_initializer_list_constructible_impl_v due to the fact that you can use is_nothrow_list_constructible_impl_v.
template <class T, class ...Args>
CONCEPT_T is_nothrow_initializer_list_constructible_v = []{
    if constexpr(is_initializer_list_constructible_v<T, Args...>)
        return is_nothrow_list_constructible_impl_v<T, Args...>;
    else
        return false;
}();

// Define of shortcut of often used concepts.
template <class T>
CONCEPT_T is_default_constructible_v              = is_direct_constructible_v<T>;
template <class T>
CONCEPT_T is_nothrow_default_constructible_impl_v = is_nothrow_direct_constructible_impl_v<T>;
template <class T>
CONCEPT_T is_nothrow_default_constructible_v      = is_nothrow_direct_constructible_v<T>;

template <class T>
CONCEPT_T is_copy_constructible_v              = is_direct_constructible_v<T, const T&>;
template <class T>
CONCEPT_T is_nothrow_copy_constructible_impl_v = is_nothrow_direct_constructible_impl_v<T, const T&>;
template <class T>
CONCEPT_T is_nothrow_copy_constructible_v      = is_nothrow_direct_constructible_v<T, const T&>;

template <class T>
CONCEPT_T is_move_constructible_v              = is_direct_constructible_v<T, T&&>;
template <class T>
CONCEPT_T is_nothrow_move_constructible_impl_v = is_nothrow_direct_constructible_impl_v<T, T&&>;
template <class T>
CONCEPT_T is_nothrow_move_constructible_v      = is_nothrow_direct_constructible_v<T, T&&>;

# define _DEF_CLASS_WRAPPER(NAME) template <class T, class ...Args> struct is_## NAME : bool_constant<is_## NAME ##_v<T, Args...>> {}
# define DEF_CLASS_WRAPPER(NAME) _DEF_CLASS_WRAPPER(NAME); _DEF_CLASS_WRAPPER(nothrow_## NAME)

DEF_CLASS_WRAPPER(direct_constructible);
DEF_CLASS_WRAPPER(list_constructible);
_DEF_CLASS_WRAPPER(nothrow_initializer_list_constructible);
DEF_CLASS_WRAPPER(default_constructible);
DEF_CLASS_WRAPPER(copy_constructible);
DEF_CLASS_WRAPPER(move_constructible);

# undef DEF_CLASS_WRAPPER
# undef _DEF_CLASS_WRAPPER

DEF_T_ARGS_CHECK_T_IMPL(direct_constructible);
DEF_T_ARGS_CHECK_T_IMPL(list_constructible);
DEF_T_ARGS_CHECK_T_IMPL(initializer_list_constructible);
DEF_T_ARGS_CHECK_T_IMPL(default_constructible);
DEF_T_ARGS_CHECK_T_IMPL(copy_constructible);
DEF_T_ARGS_CHECK_T_IMPL(move_constructible);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
