#include <type_traits>
#include "../../../include/concepts/operations/is_callable_core.hpp"
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

// Test callable_t.
template <class ...Args>
struct functor {
    template <class T>
    void operator () (callable_t<T, Args...> &&f) {}
};

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
    static_assert(std::is_same<callable_result_t<void (*)()>, void>{}());
    static_assert(std::is_same<callable_result_t<int (*)()>, int>{}());

    // Test callable_t.
    {

        functor<> F1;
        functor<int> F2;

        F1([]{});
        F2([](int){});

    }

}
