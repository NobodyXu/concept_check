#ifndef __nobodxu_concept_check_remove_cvref_t_HPP__
# define __nobodxu_concept_check_remove_cvref_t_HPP__

# include "remove_cv.hpp"
# include "remove_reference.hpp"

namespace nxwheels {
template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;
} /* nxwheels */
#endif
