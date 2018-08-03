#ifndef __nobodyxu_concept_check_concepts_operations_is_callable_core_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_callable_core_HPP__

# include "../../detector_core.hpp"
# include "../../utility.hpp"

namespace nxwheels {
template <class T, class ...Args> using operator_call = decltype( (declval<T>())(decl_as<Args>()...) );
template <class T, class ...Args> constexpr const static inline bool is_callable_v = is_detected_v<operator_call, T, Args...>;
template <class T, class ...Args> using callable_result_t = detected_t<operator_call, T, Args...>;
} /* nxwheels */
#endif
