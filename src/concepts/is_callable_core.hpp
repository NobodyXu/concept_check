#ifndef __nobodyxu_concept_check_concepts_is_callable_core_HPP__
# define __nobodyxu_concept_check_concepts_is_callable_core_HPP__
# include "../utility.hpp"
# include "../detector_core.hpp"
namespace nxwheels::concept_check {
template <class T, class ...Args>
using operator_call = decltype( (declval<T>())(decl_as<Args>()...) );
template <class T, class ...Args>
constexpr const static inline bool is_callable_v = is_detected_v<operator_call, T, Args...>;
template <class T, class ...Args>
using is_callable = detector_t<operator_call, T, Args...>;
template <class T, class ...Args>
using callable_result_t = detected_t<operator_call, T, Args...>;
} /* nxwheels::concept_check */
#endif
