#include "../../detector_v.hpp"
#include "../../utility.hpp"

#ifndef DEF_UN_CHECK
# define DEF_UN_CHECK(NAME, OP)                                                                                 \
template <class T> using NAME ##_op_ret_t = decltype( OP declval<T>() );                                             \
template <class T> constexpr const static inline bool has_## NAME ##_op_v = is_detected_v<NAME ##_op_ret_t, T>;      \
template <class T> constexpr const static inline bool has_nothrow_## NAME ##_op_impl_v = noexcept( OP declval<T>() );\
template <class T> constexpr const static inline bool has_nothrow_## NAME ##_op_v = []{                              \
    if constexpr(has_## NAME ##_op_v<T>)                                                                             \
        return has_nothrow_## NAME ##_op_impl_v<T>;                                                                  \
    else                                                                                                             \
        return false;                                                                                                \
}()
#endif

#ifndef DEF_BIN_CHECK
# define DEF_BIN_CHECK(NAME, OP)                                                                                                          \
template <class T1, class T2> using NAME ##_op_ret_t = decltype( declval<T1>() OP declval<T2>() );                                             \
template <class T1, class T2> constexpr const static inline bool has_## NAME ##_op_v = is_detected_v<NAME ##_op_ret_t, T1, T2>;                \
template <class T1, class T2> constexpr const static inline bool has_nothrow_## NAME ##_op_impl_v = noexcept( declval<T1>() OP declval<T2>() );\
template <class T1, class T2> constexpr const static inline bool has_nothrow_## NAME ##_op_v = []{                                             \
    if constexpr(has_## NAME ##_op_v<T1, T2>)                                                                                                  \
        return has_nothrow_## NAME ##_op_impl_v<T1, T2>;                                                                                       \
    else                                                                                                                                       \
        return false;                                                                                                                          \
}()
#endif

#ifndef DEF_UN_IMP_CONVERT_CHECK
# define DEF_UN_IMP_CONVERT_CHECK(NAME, OP, RET_T)                                                                                 \
template <class T> using NAME ##_op_ret_t = decltype( OP declval<T>() );                                             \
template <class T> constexpr const static inline bool has_## NAME ##_op_v = is_detected_implicitly_convertible_v<RET_T, NAME ##_op_ret_t, T>;      \
template <class T> constexpr const static inline bool has_nothrow_## NAME ##_op_impl_v = noexcept( OP declval<T>() );\
template <class T> constexpr const static inline bool has_nothrow_## NAME ##_op_v = []{                              \
    if constexpr(has_## NAME ##_op_v<T>)                                                                             \
        return has_nothrow_## NAME ##_op_impl_v<T>;                                                                  \
    else                                                                                                             \
        return false;                                                                                                \
}()
#endif

#ifndef DEF_BIN_IMP_CONVERT_CHECK
# define DEF_BIN_IMP_CONVERT_CHECK(NAME, OP, RET_T)                                                                                                          \
template <class T1, class T2> using NAME ##_op_ret_t = decltype( declval<T1>() OP declval<T2>() );                                             \
template <class T1, class T2> constexpr const static inline bool has_## NAME ##_op_v = is_detected_implicitly_convertible_v<RET_T, NAME ##_op_ret_t, T1, T2>;                \
template <class T1, class T2> constexpr const static inline bool has_nothrow_## NAME ##_op_impl_v = noexcept( declval<T1>() OP declval<T2>() );\
template <class T1, class T2> constexpr const static inline bool has_nothrow_## NAME ##_op_v = []{                                             \
    if constexpr(has_## NAME ##_op_v<T1, T2>)                                                                                                  \
        return has_nothrow_## NAME ##_op_impl_v<T1, T2>;                                                                                       \
    else                                                                                                                                       \
        return false;                                                                                                                          \
}()
#endif
