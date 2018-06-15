#ifndef __concept_check_integral_constant_HPP__
# define __concept_check_integral_constant_HPP__
namespace nxwheels::concept_check {
template <class T, T _value>
struct integral_constant {
    using value_type = T;
    using type       = integral_constant;

    constexpr const inline static T value = _value;

    constexpr T operator () () const noexcept { return value; }
    constexpr operator T ()    const noexcept { return value; }
};
template <auto val>
using integral_constant_t = integral_constant<decltype(val), val>;
template <bool val>
using bool_constant = integral_constant<bool, val>;

using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;
} /* nxwheels::concept_check */
#endif
