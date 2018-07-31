#ifndef __nobodyxu_concept_check_detector_v_HPP__
# define __nobodyxu_concept_check_detector_v_HPP__

# include <type_traits>
# include "detector_core.hpp"
# include "concepts/type_properties/operations/is_convertible_v.hpp"

namespace nxwheels {
template <class Expected, template <class...> class op, class ...Ts>
constexpr const static inline bool is_detected_exact_v = std::is_same<Expected, detected_t<op, Ts...>>::value;

template <class To, template <class...> class op, class ...Ts>
constexpr const static inline bool is_detected_implicitly_convertible_v = is_implicitly_convertible_v<detected_t<op, Ts...>, To>;
} /* nxwheels */
#endif
