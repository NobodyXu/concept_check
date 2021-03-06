#ifndef __nobodyxu_concept_check_concepts_operations_is_callable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_callable_v_HPP__

# include "../is_same.hpp"
# include "is_callable_core.hpp"
# include "is_convertible_v.hpp"

# include "../../def_convenient_macros.hpp"

namespace nxwheels {
template <class T2, class T, class ...Args> CONCEPT_T is_callable_exact_v                  = is_same_v<callable_result_t<T, Args...>, T2>;
template <class To, class T, class ...Args> CONCEPT_T is_callable_implicitly_convertible_v = is_implicitly_convertible_v<callable_result_t<T, Args...>, To>;
} /* nxwheels */

# include "../../undef_convenient_macros.hpp"

#endif
