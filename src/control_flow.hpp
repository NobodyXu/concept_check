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
# include "concepts/type_properties/member/has_ntype_type_v.hpp"

namespace nxwheels::concept_check {
template <bool condition, class when_True, class when_False> struct _if                           { using type = evaluate_t<when_True>; };
template <class when_True, class when_False>                 struct _if<0, when_True, when_False> { using type = evaluate_t<when_False>; };
template <bool condition, class when_True, class when_False> using  if_t = typename _if<condition, when_True, when_False>::type;

template <class ...Ts>          struct conjunction_impl;
template <>                     struct conjunction_impl<>         { using type = true_type; };
template <class T, class ...Ts> struct conjunction_impl<T, Ts...> { using type = if_t<!bool(T::value) || !bool(sizeof...(Ts)), T, delay<ntype_type_t, delay<conjunction_impl, Ts...>>>; };
template <class ...Ts>          using  conjunction_t = typename conjunction_impl<Ts...>::type;
template <class ...Ts>          struct conjunction: conjunction_t<Ts...> {};
template <class ...Ts>          constexpr const static inline bool conjunction_v = conjunction_t<Ts...>::value;

template <class ...Ts>          struct disjunction_impl;
template <>                     struct disjunction_impl<>         { using type = false_type; };
template <class T, class ...Ts> struct disjunction_impl<T, Ts...> { using type = if_t<bool(T::value) || !bool(sizeof...(Ts)), T, delay<ntype_type_t, delay<disjunction_impl, Ts...>>>; };
template <class ...Ts>          using  disjunction_t = typename disjunction_impl<Ts...>::type;
template <class ...Ts>          struct disjunction: disjunction_t<Ts...> {};
template <class ...Ts>          constexpr const static inline bool disjunction_v = disjunction_t<Ts...>::value;

/*!
 * else_if_t is intended to make chaining if_t easier.
 * But it requires a helper class to wrap the boolean value and the type.
 * This file also defines branch, a simple wrapper over boolean value and the type, intended to free the usrs from writing boilerplate.
 */
template <class ...else_if_bundles> struct _else_if { using type = typename disjunction_t<else_if_bundles...>::type; };
template <class ...else_if_bundles> using  else_if_t = typename disjunction_t<else_if_bundles...>::type;

/*!
 * branch is a simple wrapper over boolean value and a type, intended to free usr who uses else_if_t from writing boilerplate.
 */
template <bool condition, class T>
struct branch {
    constexpr const static inline bool value = condition;
    typedef T type;
};
} /* nxwheels::concept_check */
#endif
