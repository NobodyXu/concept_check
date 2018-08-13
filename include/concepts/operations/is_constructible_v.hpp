#ifndef __nobodyxu_concept_check_is_constructible_v_HPP__
# define __nobodyxu_concept_check_is_constructible_v_HPP__

# include <new>
# include <type_traits>
# include "../../detector_core.hpp"
# include "../../partial_apply.hpp"
# include "../../type_tuple.hpp"
# include "../../utility.hpp"

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

# define _DEF_CLASS_WRAPPER(NAME) template <class T, class ...Args> struct is_## NAME : bool_constant<is_## NAME ##_v<T, Args...>> {}
# define DEF_CLASS_WRAPPER(NAME) _DEF_CLASS_WRAPPER(NAME); _DEF_CLASS_WRAPPER(nothrow_## NAME)

DEF_CLASS_WRAPPER(direct_constructible);
DEF_CLASS_WRAPPER(list_constructible);
DEF_CLASS_WRAPPER(initializer_list_constructible);

# undef DEF_CLASS_WRAPPER
# undef _DEF_CLASS_WRAPPER

# define DEF_T_ARGS_CHECK_T(NAME)                                                                                                                                  \
template <class T, class para_tuple, class = std::enable_if_t<apply_to_t<PARTIAL_APPLY_T(is_## NAME ##ible, T), para_tuple>::value> > using NAME ##ible_t_impl = T;\
template <class T, class ...Args> using NAME ##ible_t = NAME ##ible_t_impl<T, type_tuple<Args...>>;                                                                \
template <class T, class para_tuple, class = std::enable_if_t<apply_to_t<PARTIAL_APPLY_T(is_nothrow_## NAME ##ible, T), para_tuple>::value> > using nothrow_## NAME ##ible_t_impl = T;\
template <class T, class ...Args> using nothrow_## NAME ##ible_t = nothrow_## NAME ##ible_t_impl<T, type_tuple<Args...>>;

DEF_T_ARGS_CHECK_T(direct_construct);
DEF_T_ARGS_CHECK_T(list_construct);
DEF_T_ARGS_CHECK_T(initializer_list_construct);

# undef DEF_T_ARGS_CHECK_T
} /* nxwheels */
#endif
