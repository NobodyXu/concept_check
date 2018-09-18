#ifndef __nobodyxu_concept_check_detector_v_HPP__
# define __nobodyxu_concept_check_detector_v_HPP__

# include "detector_core.hpp"
# include "concepts/operations/is_convertible_v.hpp"

# include "def_convenient_macros.hpp"

namespace nxwheels {
template <class To, template <class...> class op, class ...Ts>
CONCEPT_T is_detected_implicitly_convertible_v = is_implicitly_convertible_v<detected_t<op, Ts...>, To>;
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
