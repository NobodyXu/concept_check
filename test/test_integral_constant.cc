#include <type_traits>
#include "../src/integral_constant.hpp"
using namespace nxwheels::concept_check;

template <class T, T val>
constexpr void test_integral_constant() noexcept {
    typedef integral_constant<T, val> type;

    static_assert(std::is_same<typename type::value_type, T>{}());
    static_assert(std::is_same<typename type::type, type>{}());

    static_assert(type::value == val);
    static_assert(type{}() == val);
    static_assert(static_cast<T>(type{}) == val);
}
template <class T, T val>
constexpr void test_integral_constant_t() noexcept {
    static_assert(std::is_same<integral_constant<T, val>, integral_constant_t<val>>{}());
}
template <bool val>
constexpr void test_bool_constant() noexcept {
    static_assert(std::is_same<bool_constant<val>, integral_constant<bool, val>>{}());
}
int main() {
    test_integral_constant<int, 2333>();
    test_integral_constant_t<int, 2333>();
    test_bool_constant<false>();
    test_bool_constant<true>();

    // Test true_type and false_type;
    static_assert(std::is_same<true_type, integral_constant<bool, true>>{}());
    static_assert(std::is_same<false_type, integral_constant<bool, false>>{}());
}
