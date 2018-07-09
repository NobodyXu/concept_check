#ifndef __nobodyxu_concept_check_delay_HPP__
# define __nobodyxu_concept_check_delay_HPP__
namespace nxwheels {
/*!
 * class delay will delay the instantiation of op<Ts...>.
 */
template <template <class...> class op, class ...Ts>
struct delay {};

template <class T>                                   struct evaluate                   { using type = T; };
template <template <class...> class op, class ...Ts> struct evaluate<delay<op, Ts...>> { using type = op<typename evaluate<Ts>::type...>; };

template <class T> using evaluate_t = typename evaluate<T>::type;
} /* nxwheels */
#endif