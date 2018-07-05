#ifndef __nobodyxu_concept_check_concepts_type_properties_operations_is_convertible_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_operations_is_convertible_v_HPP__

# include "../../../utility.hpp"
# include "../../is_void_v.hpp"
# include "is_callable_core.hpp"

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
template <class T>              constexpr const static inline auto lambda = [](T) noexcept {};
template <class T>              using lambda_t = decltype(lambda<T>);
template <class From, class To> constexpr const static inline bool noexcept_convert_v = noexcept( lambda<To>(declval<From>()) );
} /* nxwheels::concept_check::is_convertible_impl */

namespace nxwheels::concept_check {
template <class From, class To> constexpr const static inline bool is_implicitly_convertible_v = []{
    if constexpr(is_void_v<To>)
        return true;
    else
        return is_callable_v<is_convertible_impl::lambda_t<To>, From>;
}();
DEF_ASSERT(implicitly_convertible);

template <class From, class To> constexpr const static inline bool is_nothrow_implicitly_convertible_v = []{
    if constexpr(is_implicitly_convertible_v<From, To>)
        return is_convertible_impl::noexcept_convert_v<From, To>;
    else
        return false;
}();
DEF_ASSERT(nothrow_implicitly_convertible);
} /* nxwheels::concept_check */
#endif