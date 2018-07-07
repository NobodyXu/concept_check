#ifndef __nobodyxu_concept_check_detector_v_HPP__
# define __nobodyxu_concept_check_detector_v_HPP__

# include "detector_core.hpp"
# include "concepts/is_same.hpp"
# include "concepts/type_properties/operations/is_convertible_v.hpp"

namespace nxwheels::concept_check {
template <class Expected, template <class...> class op, class ...Ts>
constexpr const static inline bool is_detected_exact_v = is_same_v<Expected, detected_t<op, Ts...>>;

template <class To, template <class...> class op, class ...Ts>
constexpr const static inline bool is_detected_implicitly_convertible_v = is_implicitly_convertible_v<detected_t<op, Ts...>, To>;
} /* nxwheels::concept_check */
#endif
