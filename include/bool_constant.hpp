#ifndef __nobodyxu_concept_check_bool_constant_HPP__
# define __nobodyxu_concept_check_bool_constant_HPP__

namespace nxwheels {
template <bool _value> struct bool_constant { constexpr const inline static bool value = _value; };

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;
} /* nxwheels */
#endif
