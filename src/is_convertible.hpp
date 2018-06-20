#ifndef __nobodyxu_concept_check_is_convertible_HPP__
# define __nobodyxu_concept_check_is_convertible_HPP__

# include "integral_constant.hpp"
# include "control_flow.hpp"
# include "concepts/is_callable_core.hpp"
# include "concepts/is_void.hpp"

namespace nxwheels::concept_check::is_convertible_impl {
template <class T>
auto lambda = [](T){};
template <class T>
using lambda_t = decltype(lambda<T>);
} /* nxwheels::concept_check::is_convertible_impl */

namespace nxwheels::concept_check {
template <class From, class To>
using is_implicitly_convertible = if_t<is_void_v<To>, true_type, is_callable<is_convertible_impl::lambda_t<To>, From>>;
template <class From, class To>
constexpr const static inline bool is_implicitly_convertible_v = is_implicitly_convertible<From, To>::value;
/*
template <class From, class To>
constexpr const static inline bool is_nothrow_implicitly_convertible_v = [] {
    if constexpr(is_implicitly_convertible_v<From, To>)
        return noexcept(To(declval<From>()));
    else
        return false;
}();
template <class From, class To>
using is_nothrow_implicitly_convertible = bool_constant<is_nothrow_implicitly_convertible_v<From, To>>;
*/
} /* nxwheels::concept_check */
#endif
