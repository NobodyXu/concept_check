#ifndef __nobodyxu_concept_check_concepts_operations_is_convertible_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_convertible_v_HPP__

# include <type_traits>
# include "../../utility.hpp"
# include "is_callable_core.hpp"

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

template <class T1, class T2, class = std::enable_if_t<is_implicitly_convertible_v<T1, T2>>> using implicitly_convertible_t = T1;
template <class T1, class T2, class = std::enable_if_t<is_nothrow_implicitly_convertible_v<T1, T2>>> using nothrow_implicitly_convertiable_t = T1;
} /* nxwheels */
#endif
