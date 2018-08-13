# include <type_traits>
# include "../../detector_core.hpp"
# include "../../partial_apply.hpp"
# include "../../type_tuple.hpp"
# include "../../utility.hpp"

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

#ifndef DEF_UN_CHECK_T
# define DEF_UN_CHECK_T(NAME)                                                                                   \
template <class T, class = std::enable_if_t<is_## NAME ##able_v<T>>> using NAME ##able_t = T;                   \
template <class T, class = std::enable_if_t<is_nothrow_## NAME ##able_v<T>>> using nothrow_## NAME ##able_t = T;
#endif

#ifndef DEF_BIN_CHECK_T
# define DEF_BIN_CHECK_T(NAME)                                                                                                   \
template <class T1, class T2, class = std::enable_if_t<is_## NAME ##able_v<T1, T2>>> using NAME ##able_t = T1;                   \
template <class T1, class T2, class = std::enable_if_t<is_nothrow_## NAME ##able_v<T1, T2>>> using nothrow_## NAME ##able_t = T1;
#endif

#ifndef DEF_T_ARGS_CHECK_T
# define DEF_T_ARGS_CHECK_T(NAME)                                                                                                                                  \
template <class T, class para_tuple, class = std::enable_if_t<apply_to_t<PARTIAL_APPLY_T(is_## NAME ##able, T), para_tuple>::value> > using NAME ##able_t_impl = T;\
template <class T, class ...Args> using NAME ##able_t = NAME ##able_t_impl<T, type_tuple<Args...>>;                                                                \
template <class T, class para_tuple, class = std::enable_if_t<apply_to_t<PARTIAL_APPLY_T(is_nothrow_## NAME ##able, T), para_tuple>::value> > using nothrow_## NAME ##able_t_impl = T;\
template <class T, class ...Args> using nothrow_## NAME ##able_t = nothrow_## NAME ##able_t_impl<T, type_tuple<Args...>>;
#endif
