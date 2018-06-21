#ifndef __nobodyxu_concept_check_concepts_is_callable_HPP__
# define __nobodyxu_concept_check_concepts_is_callable_HPP__
# include "is_callable_core.hpp"
# include "../is_same.hpp"
# include "is_convertible.hpp"
namespace nxwheels::concept_check {
template <class T2, class T, class ...Args>
using is_callable_exact = is_same<callable_result_t<T, Args...>, T2>;
template <class T2, class T, class ...Args>
constexpr const static inline bool is_callable_exact_v = is_callable_exact<T2, T, Args...>::value;

template <class To, class T, class ...Args>
using is_callable_implicitly_convertible = is_implicitly_convertible<callable_result_t<T, Args...>, To>;
template <class To, class T, class ...Args>
constexpr const static inline bool is_callable_implicitly_convertible_v = is_callable_implicitly_convertible<To, T, Args...>::value;
} /* nxwheels::concept_check */
#endif
