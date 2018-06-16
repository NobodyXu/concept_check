#include <type_traits>
#include "../src/utility.hpp"
using namespace nxwheels::concept_check;

struct Foo {};

template <class T, class _T>
void test_callee_example(_T &&) noexcept {
    static_assert(std::is_same<T, _T>{}());
}
template <class T>
void test_caller_example(T &&t) noexcept {
    test_callee_example<T>(forward<T>(t));
}

template <class T>
void _test() noexcept {
    test_caller_example(decl_as<T&>());
    // The 2 below should be the same.
    test_caller_example(decl_as<T&&>());
    test_caller_example(decl_as<T>());
}
template <class T>
void test() noexcept {
    _test<T>();
    _test<T*>();
    _test<T Foo::*>();
    _test<T (Foo::*)()>();
}
int main() {
    typedef void (*fp)();
    fp parray[] = {&test<char>, &test<int>, &test<Foo>, &_test<void*>};
}
