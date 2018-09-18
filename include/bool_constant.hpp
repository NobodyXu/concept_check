#ifndef __nobodyxu_concept_check_bool_constant_HPP__
# define __nobodyxu_concept_check_bool_constant_HPP__

# include "def_convenient_macros.hpp"

namespace nxwheels {
template <bool _value> struct bool_constant { CONCEPT_T value = _value; };

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;
} /* nxwheels */

# include "undef_convenient_macros.hpp"

#endif
