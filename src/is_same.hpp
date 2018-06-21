#ifndef __nobodyxu_concept_check_is_same_HPP__
# define __nobodyxu_concept_check_is_same_HPP__
# include "integral_constant.hpp"
namespace nxwheels::concept_check {
template <class T1, class T2>
struct is_same: false_type {};
template <class T>
struct is_same<T, T>: true_type {};
template <class T1, class T2>
constexpr const static inline bool is_same_v = is_same<T1, T2>::value;

template <class T1, class T2>
struct assert_same_t {
    static_assert(is_same_v<T1, T2>);
};
template <class T1, class T2>
constexpr void assert_same() noexcept {
    static_assert(is_same_v<T1, T2>);
}

template <class T1, class T2>
struct assert_not_same_t {
    static_assert(!is_same_v<T1, T2>);
};
template <class T1, class T2>
constexpr void assert_not_same() noexcept {
    static_assert(!is_same_v<T1, T2>);
}
} /* nxwheels::concept_check */
#endif
