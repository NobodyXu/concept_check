#ifndef __nobodyxu_concept_check_concepts_operations_is_convertible_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_convertible_v_HPP__

# include "../is_same.hpp"
# include "is_callable_core.hpp"

# define DONT_USE_DETECTOR_V
# include "def_convenient_macros.hpp"
# undef  DONT_USE_DETECTOR_V

namespace nxwheels {
template <class T> CONSTEXPR_GLOBAL_VAR auto lambda_for_implicit_conversion = [](T) noexcept {};
template <class T> using lambda_for_implicit_conversion_t = decltype(lambda_for_implicit_conversion<T>);

template <class From, class To> CONCEPT_T is_implicitly_convertible_v = []{
    if constexpr(is_same_v<To, void>)
        return true;
    else
        return is_callable_v<lambda_for_implicit_conversion_t<To>, From>;
}();

template <class From, class To>
CONCEPT_T is_nothrow_implicitly_convertible_impl_v = noexcept( lambda_for_implicit_conversion<To>(declval<From>()) );
template <class From, class To> CONCEPT_T is_nothrow_implicitly_convertible_v = []{
    if constexpr(is_implicitly_convertible_v<From, To>)
        return is_nothrow_implicitly_convertible_impl_v<From, To>;
    else
        return false;
}();

DEF_BIN_CHECK_T_IMPL(implicitly_convertible);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
