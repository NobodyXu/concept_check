#ifndef __nobodyxu_concept_check_concepts_operations_is_callable_core_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_callable_core_HPP__

# include <type_traits>
# include "../../detector_core.hpp"
# include "../../utility.hpp"

namespace nxwheels {
# define DEF_TMP template <class T, class ...Args>
# define VAR constexpr const static inline bool

DEF_TMP using called_ret_t = decltype( (declval<T>())(decl_as<Args>()...) );
DEF_TMP VAR is_callable_v = is_detected_v<called_ret_t, T, Args...>;
DEF_TMP VAR is_nothrow_callable_impl_v = noexcept( (declval<T>())(decl_as<Args>()...) );
DEF_TMP VAR is_nothrow_callable_v = []{
    if constexpr(is_callable_v<T, Args...>)
        return is_nothrow_callable_impl_v<T, Args...>;
    else
        return false;
}();
DEF_TMP using callable_result_t = detected_t<called_ret_t, T, Args...>;

# undef VAR
# undef DEF_TMP

template <class T, class ...Args> using callable_t = std::enable_if_t<is_callable_v<T, Args...>, T>;
} /* nxwheels */
#endif
