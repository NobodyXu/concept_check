#ifndef __nobodyxu_concept_check_add_cv_t_HPP__
# define __nobodyxu_concept_check_add_cv_t_HPP__

namespace nxwheels {
template <class T> using add_const_t    = const T;
template <class T> using add_volatile_t = volatile T;
template <class T> using add_cv_t       = add_const_t<add_volatile_t<T>>;
} /* nxwheels */
#endif
