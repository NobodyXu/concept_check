#ifndef __nobodyxu_concept_check_concepts_operations_is_callable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_callable_v_HPP__

# include <type_traits>
# include "is_callable_core.hpp"
# include "is_convertible_v.hpp"

namespace nxwheels {
template <class T2, class T, class ...Args> constexpr const static inline bool is_callable_exact_v                  = std::is_same<callable_result_t<T, Args...>, T2>::value;
template <class To, class T, class ...Args> constexpr const static inline bool is_callable_implicitly_convertible_v = is_implicitly_convertible_v<callable_result_t<T, Args...>, To>;
} /* nxwheels */
#endif
