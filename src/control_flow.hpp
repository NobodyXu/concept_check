/*!
 * This file contains control flows for template meta programming.
 * In order to be consistent with ```if```, ```else``` and other control flow statement used in normal programming, but not conflict with C++ standard
 * names, an underscore will be inserted before the original class name.
 * All the template in this file supports lazy instantiation of the result type.
 */
#ifndef __nobodyxu_concept_check_control_flow_HPP__
# define __nobodyxu_concept_check_control_flow_HPP__

# include "detector_core.hpp"
# include "delay.hpp"
# include "concepts/has_nested_type_type.hpp"

namespace nxwheels::concept_check {
template <bool condition, class when_True, class when_False>
struct _if {
    typedef evaluate_t<when_True> type;
};
template <class when_True, class when_False>
struct _if<0, when_True, when_False> {
    typedef evaluate_t<when_False> type;
};
template <bool condition, class when_True, class when_False> using if_t = typename _if<condition, when_True, when_False>::type;

template <class ...Ts> struct disjunction_impl;
template <class T, class ...Ts>
struct disjunction_impl<T, Ts...> {
    using type = if_t<bool(T::value) || !bool(sizeof...(Ts)),
                        T,
                        delay<nested_type_type_t, delay<disjunction_impl, Ts...>>
    >;
};
template <>
struct disjunction_impl<> {
    using type = false_type;
};
template <class ...Ts> using disjunction_t = typename disjunction_impl<Ts...>::type;
template <class ...Ts>
struct disjunction: disjunction_t<Ts...> {};
template <class ...Ts>
constexpr const static inline bool disjunction_v = disjunction_t<Ts...>::value;

/*!
 * else_if_t is intended to make chaining if_t easier.
 * But it requires a helper class to wrap the boolean value and the type.
 */
template <bool condition, class T>
struct branch {
    constexpr const static inline bool value = condition;
    typedef T type;
};
template <class ...else_if_bundles>
struct _else_if {
    using type = typename disjunction_t<else_if_bundles...>::type;
};
template <class ...else_if_bundles>
using else_if_t = typename _else_if<else_if_bundles...>::type;
} /* nxwheels::concept_check */
#endif
