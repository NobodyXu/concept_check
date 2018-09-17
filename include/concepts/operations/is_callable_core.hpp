#ifndef __nobodyxu_concept_check_concepts_operations_is_callable_core_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_callable_core_HPP__

# define DONT_USE_DETECTOR_V
# include "def_convenient_macros.hpp"
# undef  DONT_USE_DETECTOR_V

namespace nxwheels {
# define DEF_TMP template <class T, class ...Args>
# define VAR constexpr const static inline bool

DEF_TMP using called_ret_t = decltype( (declval<T>())(decl_as<Args>()...) );
DEF_TMP using is_callable = is_detected<called_ret_t, T, Args...>;

DEF_TMP VAR is_callable_v = is_detected_v<called_ret_t, T, Args...>;
DEF_TMP VAR is_nothrow_callable_impl_v = noexcept( (declval<T>())(decl_as<Args>()...) );
DEF_TMP VAR is_nothrow_callable_v = []{
    if constexpr(is_callable_v<T, Args...>)
        return is_nothrow_callable_impl_v<T, Args...>;
    else
        return false;
}();
DEF_TMP struct is_nothrow_callable: bool_constant<is_nothrow_callable_v<T, Args...>> {};
DEF_TMP using callable_result_t = detected_t<called_ret_t, T, Args...>;

# undef VAR
# undef DEF_TMP

DEF_T_ARGS_CHECK_T(call);
} /* nxwheels */

# include "def_convenient_macros.hpp"

#endif
