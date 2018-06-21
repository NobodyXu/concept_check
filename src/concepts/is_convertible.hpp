#ifndef __nobodyxu_concept_check_is_convertible_HPP__
# define __nobodyxu_concept_check_is_convertible_HPP__

# include "../control_flow.hpp"
# include "../utility.hpp"
# include "is_callable_core.hpp"
# include "is_void.hpp"

# define DEF_ASSERT(CONVERT)                      \
template <class From, class To>                   \
constexpr void assert_## CONVERT () noexcept {    \
    static_assert(is_## CONVERT ##_v<From, To>);  \
}                                                 \
template <class From, class To>                   \
struct assert_## CONVERT ##_t {                   \
    static_assert(is_## CONVERT ##_v<From, To>);  \
};                                                \
                                                  \
template <class From, class To>                   \
constexpr void assert_not_## CONVERT () noexcept {\
    static_assert(!is_## CONVERT ##_v<From, To>); \
}                                                 \
template <class From, class To>                   \
struct assert_not_## CONVERT ##_t {               \
    static_assert(!is_## CONVERT ##_v<From, To>); \
}

namespace nxwheels::concept_check::is_convertible_impl {
template <class T> constexpr const static inline auto lambda = [](T) noexcept {};
template <class T> using lambda_t = decltype(lambda<T>);

template <class From, class To>
constexpr const static inline bool noexcept_convert_v = noexcept( lambda<To>(decl_as<From>()) );
template <class From, class To>
using noexcept_convert = bool_constant<noexcept_convert_v<From, To>>;
} /* nxwheels::concept_check::is_convertible_impl */

namespace nxwheels::concept_check {
template <class From, class To>
using is_implicitly_convertible = if_t< is_void_v<To>, true_type, delay<is_callable, delay<is_convertible_impl::lambda_t, To>, From> >;
template <class From, class To>
constexpr const static inline bool is_implicitly_convertible_v = is_implicitly_convertible<From, To>::value;
DEF_ASSERT(implicitly_convertible);

template <class From, class To>
using is_nothrow_implicitly_convertible = if_t<is_implicitly_convertible_v<From, To>, delay<is_convertible_impl::noexcept_convert, From, To>, false_type>;
template <class From, class To>
constexpr const static inline bool is_nothrow_implicitly_convertible_v = is_nothrow_implicitly_convertible<From, To>::value;
DEF_ASSERT(nothrow_implicitly_convertible);
} /* nxwheels::concept_check */
#endif
