#ifndef __nobodyxu_concept_check_enable_if_HPP__
# define __nobodyxu_concept_check_enable_if_HPP__

namespace nxwheels {
template <bool value, class T = void> struct enable_if          {};
template <class T>                    struct enable_if<true, T> { using type = T; };

template <bool value, class T = void> using enable_if_t = typename enable_if<value, T>::type;
} /* nxwheels */
#endif
