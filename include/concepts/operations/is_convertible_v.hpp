#ifndef __nobodyxu_concept_check_concepts_operations_is_convertible_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_convertible_v_HPP__

# include <type_traits>
# include "is_callable_core.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class T> constexpr const static inline auto lambda_for_implicit_conversion = [](T) noexcept {};
template <class T> using lambda_for_implicit_conversion_t = decltype(lambda_for_implicit_conversion<T>);

template <class From, class To> constexpr const static inline bool is_implicitly_convertible_v = []{
    if constexpr(std::is_void<To>::value)
        return true;
    else
        return is_callable_v<lambda_for_implicit_conversion_t<To>, From>;
}();

template <class From, class To>
constexpr const static inline bool is_nothrow_implicitly_convertible_impl_v = noexcept( lambda_for_implicit_conversion<To>(declval<From>()) );
template <class From, class To> constexpr const static inline bool is_nothrow_implicitly_convertible_v = []{
    if constexpr(is_implicitly_convertible_v<From, To>)
        return is_nothrow_implicitly_convertible_impl_v<From, To>;
    else
        return false;
}();

DEF_BIN_CHECK_T_IMPL(implicitly_convertible);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
