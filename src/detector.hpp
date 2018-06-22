#ifndef __nobodyxu_concept_check_detector_HPP__
# define __nobodyxu_concept_check_detector_HPP__
# include "detector_core.hpp"
# include "concepts/is_same.hpp"
# include "concepts/type_properties/operations/is_convertible.hpp"
namespace nxwheels::concept_check {
template <class Expected, template <class...> class op, class ...Ts>
using is_detected_exact = is_same<Expected, detected_t<op, Ts...>>;
template <class Expected, template <class...> class op, class ...Ts>
constexpr const static inline bool is_detected_exact_v = is_detected_exact<Expected, op, Ts...>::value;

template <class To, template <class...> class op, class ...Ts>
using is_detected_implicitly_convertible = is_implicitly_convertible<detected_t<op, Ts...>, To>;
template <class To, template <class...> class op, class ...Ts>
constexpr const static inline bool is_detected_implicitly_convertible_v = is_detected_implicitly_convertible<To, op, Ts...>::value;
} /* nxwheels::concept_check */
#endif
