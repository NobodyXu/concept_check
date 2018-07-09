#ifndef __nobodyxu_concept_check_usefull_types_HPP__
# define __nobodyxu_concept_check_usefull_types_HPP__

# include "utility.hpp"

namespace nxwheels {
typedef decltype(sizeof(char)) size_t;
typedef decltype(declval<char*>() - declval<char*>()) ptrdiff_t;
} /* nxwheels */
#endif
