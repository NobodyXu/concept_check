# include "../../enable_if.hpp"
# include "../../partial_apply.hpp"
# include "../../type_tuple.hpp"
# include "../../utility.hpp"

#ifdef DONT_USE_DETECTOR_V
# include "../../detector_core.hpp"
#else
# include "../../detector_v.hpp"
#endif

#ifndef DEF_UN_CHECK
# define DEF_UN_CHECK(NAME, OP)                                                                                 \
template <class T> using NAME ##ed_ret_t = decltype( OP declval<T>() );                                             \
template <class T> constexpr const static inline bool is_## NAME ##able_v = is_detected_v<NAME ##ed_ret_t, T>;      \
template <class T> constexpr const static inline bool is_nothrow_## NAME ##able_impl_v = noexcept( OP declval<T>() );\
template <class T> constexpr const static inline bool is_nothrow_## NAME ##able_v = []{                              \
    if constexpr(is_## NAME ##able_v<T>)                                                                             \
        return is_nothrow_## NAME ##able_impl_v<T>;                                                                  \
    else                                                                                                             \
        return false;                                                                                                \
}()
#endif

#ifndef DEF_BIN_CHECK
# define DEF_BIN_CHECK(NAME, OP)                                                                                                          \
template <class T1, class T2> using NAME ##ed_ret_t = decltype( declval<T1>() OP declval<T2>() );                                             \
template <class T1, class T2> constexpr const static inline bool is_## NAME ##able_v = is_detected_v<NAME ##ed_ret_t, T1, T2>;                \
template <class T1, class T2> constexpr const static inline bool is_nothrow_## NAME ##able_impl_v = noexcept( declval<T1>() OP declval<T2>() );\
template <class T1, class T2> constexpr const static inline bool is_nothrow_## NAME ##able_v = []{                                             \
    if constexpr(is_## NAME ##able_v<T1, T2>)                                                                                                  \
        return is_nothrow_## NAME ##able_impl_v<T1, T2>;                                                                                       \
    else                                                                                                                                       \
        return false;                                                                                                                          \
}()
#endif

#ifndef DEF_UN_IMP_CONVERT_CHECK
# define DEF_UN_IMP_CONVERT_CHECK(NAME, OP, RET_T)                                                                                 \
template <class T> using NAME ##ed_ret_t = decltype( OP declval<T>() );                                             \
template <class T> constexpr const static inline bool is_## NAME ##able_v = is_detected_implicitly_convertible_v<RET_T, NAME ##ed_ret_t, T>;      \
template <class T> constexpr const static inline bool is_nothrow_## NAME ##able_impl_v = noexcept( OP declval<T>() );\
template <class T> constexpr const static inline bool is_nothrow_## NAME ##able_v = []{                              \
    if constexpr(is_## NAME ##able_v<T>)                                                                             \
        return is_nothrow_## NAME ##able_impl_v<T>;                                                                  \
    else                                                                                                             \
        return false;                                                                                                \
}()
#endif

#ifndef DEF_BIN_IMP_CONVERT_CHECK
# define DEF_BIN_IMP_CONVERT_CHECK(NAME, OP, RET_T)                                                                                                          \
template <class T1, class T2> using NAME ##ed_ret_t = decltype( declval<T1>() OP declval<T2>() );                                             \
template <class T1, class T2> constexpr const static inline bool is_## NAME ##able_v = is_detected_implicitly_convertible_v<RET_T, NAME ##ed_ret_t, T1, T2>;                \
template <class T1, class T2> constexpr const static inline bool is_nothrow_## NAME ##able_impl_v = noexcept( declval<T1>() OP declval<T2>() );\
template <class T1, class T2> constexpr const static inline bool is_nothrow_## NAME ##able_v = []{                                             \
    if constexpr(is_## NAME ##able_v<T1, T2>)                                                                                                  \
        return is_nothrow_## NAME ##able_impl_v<T1, T2>;                                                                                       \
    else                                                                                                                                       \
        return false;                                                                                                                          \
}()
#endif

#ifndef DEF_UN_CHECK_T_IMPL_IMPL
# define DEF_UN_CHECK_T_IMPL_IMPL(NAME)                                         \
template <class T, class = enable_if_t<is_## NAME ##_v<T>>> using NAME ##_t = T
#endif

#ifndef DEF_UN_CHECK_T_IMPL
# define DEF_UN_CHECK_T_IMPL(NAME) DEF_UN_CHECK_T_IMPL_IMPL(NAME); DEF_UN_CHECK_T_IMPL_IMPL(nothrow_## NAME)
#endif

#ifndef DEF_UN_CHECK_T
# define DEF_UN_CHECK_T(NAME) DEF_UN_CHECK_T_IMPL(NAME ##able)
#endif

#ifndef DEF_BIN_CHECK_T_IMPL_IMPL
# define DEF_BIN_CHECK_T_IMPL_IMPL(NAME)                                                         \
template <class T1, class T2, class = enable_if_t<is_## NAME ##_v<T1, T2>>> using NAME ##_t = T1
#endif

#ifndef DEF_BIN_CHECK_T_IMPL
# define DEF_BIN_CHECK_T_IMPL(NAME) DEF_BIN_CHECK_T_IMPL_IMPL(NAME); DEF_BIN_CHECK_T_IMPL_IMPL(nothrow_## NAME)
#endif

#ifndef DEF_BIN_CHECK_T
# define DEF_BIN_CHECK_T(NAME) DEF_BIN_CHECK_T_IMPL(NAME ##able)
#endif

#ifndef DEF_T_ARGS_CHECK_T_IMPL_IMPL
# define DEF_T_ARGS_CHECK_T_IMPL_IMPL(NAME)                                                                                                        \
template <class T, class para_tuple, class = enable_if_t<apply_to_t<PARTIAL_APPLY_T(is_## NAME, T), para_tuple>::value> > using NAME ##_t_impl = T;\
template <class T, class ...Args> using NAME ##_t = NAME ##_t_impl<T, type_tuple<Args...>>;
#endif

#ifndef DEF_T_ARGS_CHECK_T_IMPL
# define DEF_T_ARGS_CHECK_T_IMPL(NAME) DEF_T_ARGS_CHECK_T_IMPL_IMPL(NAME); DEF_T_ARGS_CHECK_T_IMPL_IMPL(nothrow_## NAME)
#endif

#ifndef DEF_T_ARGS_CHECK_T
# define DEF_T_ARGS_CHECK_T(NAME) DEF_T_ARGS_CHECK_T_IMPL(NAME ##able)
#endif
