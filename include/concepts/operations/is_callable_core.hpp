#ifndef __nobodyxu_concept_check_concepts_operations_is_callable_core_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_callable_core_HPP__

# define DONT_USE_DETECTOR_V
# include "def_convenient_macros.hpp"
# undef  DONT_USE_DETECTOR_V

namespace nxwheels {
template <class T, class ...Args>
using called_ret_t = decltype( (declval<T>())(decl_as<Args>()...) );
template <class T, class ...Args>
using is_callable = is_detected<called_ret_t, T, Args...>;

template <class T, class ...Args>
CONCEPT_T is_callable_v = is_detected_v<called_ret_t, T, Args...>;

template <class T, class ...Args>
CONCEPT_T is_nothrow_callable_impl_v = noexcept( (declval<T>())(decl_as<Args>()...) );
template <class T, class ...Args>
CONCEPT_T is_nothrow_callable_v = []{
    if constexpr(is_callable_v<T, Args...>)
        return is_nothrow_callable_impl_v<T, Args...>;
    else
        return false;
}();

template <class T, class ...Args>
struct is_nothrow_callable: bool_constant<is_nothrow_callable_v<T, Args...>> {};
template <class T, class ...Args>
using callable_result_t = detected_t<called_ret_t, T, Args...>;

DEF_T_ARGS_CHECK_T(call);
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
