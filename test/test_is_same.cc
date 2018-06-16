#include "../src/is_same.hpp"
using namespace nxwheels::concept_check;

struct Foo {};

template <class T>
void _test_should_true() noexcept {
    static_assert(is_same_v<T, T>);
}
template <class T>
void test_should_true() noexcept {
    _test_should_true<T>();
    _test_should_true<T*>();
    _test_should_true<T Foo::*>();
    _test_should_true<T (Foo::*)()>();
}

template <class T1, class T2>
struct assert_false {
    static_assert(!is_same_v<T1, T2>);
};

int main() {
    test_should_true<char>();
    test_should_true<int>();
    test_should_true<Foo>();

    _test_should_true<void*>();

    // Test when should false
    assert_false<int, char> a1{};
    assert_false<int, void> a2{};
    assert_false<int, void*> a3{};
    assert_false<Foo, void*> a4{};
    assert_false<Foo, void> a5{};
    assert_false<Foo, int> a6{};
}
