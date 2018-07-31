#include <tuple>
#include "../../../../include/concepts/is_same.hpp"
#include "../../../../include/concepts/type_properties/operations/is_callable_core.hpp"
using namespace nxwheels;

void function() {}
int function2() { return 1; }
struct functor1 {
    void operator () () {}
};
struct functor2 {
    int operator () () { return {}; }
};
auto lambda1 = []{};
auto lambda2 = []{ return 2; };
struct convert_callable1 {
    constexpr operator auto() { return &function; }
};
struct convert_callable3 {
    constexpr operator auto() { return &function2; }
};
struct convert_callable2 {
    constexpr operator auto() const { return &function; }
};

struct not_callable {};

int main() {
    // Test is_callable_v.
    static_assert(!is_callable_v<int>);
    static_assert(!is_callable_v<not_callable>);
    static_assert(!is_callable_v<const convert_callable1>);

    static_assert(is_callable_v<void (*)()>);
    static_assert(is_callable_v<int (*)()>);
    static_assert(is_callable_v<int (*)(int), int>);
    static_assert(is_callable_v<functor1>);
    static_assert(is_callable_v<functor2>);
    static_assert(is_callable_v<decltype(lambda1)>);
    static_assert(is_callable_v<decltype(lambda2)>);

    static_assert(is_callable_v<convert_callable1>);
    static_assert(is_callable_v<convert_callable2>);
    static_assert(is_callable_v<const convert_callable2>);

    // Test callable_result_t.
    std::tuple<assert_same_t<callable_result_t<void (*)()>, void>,
               assert_same_t<callable_result_t<int (*)()>, int>,
               assert_same_t<callable_result_t<int (*)(int), int>, int>,
               assert_same_t<callable_result_t<functor1>, void>,
               assert_same_t<callable_result_t<functor2>, int>,
               assert_same_t<callable_result_t<decltype(lambda1)>, void>,
               assert_same_t<callable_result_t<decltype(lambda2)>, int>,
               assert_same_t<callable_result_t<convert_callable1>, void>,
               assert_same_t<callable_result_t<convert_callable3>, int>   > tuple{};
}
