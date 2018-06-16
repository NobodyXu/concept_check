#include <type_traits>
#include "../src/add_reference.hpp"
using namespace nxwheels::concept_check;

template <class T1, class T2>
struct assert_same {
    static_assert(std::is_same<T1, T2>{}());
};
template <class T1, class T2>
struct assert_add_lvalue_ref_t: assert_same<T1, add_lvalue_reference_t<T2>> {};
template <class T1, class T2>
struct assert_add_rvalue_ref_t: assert_same<T1, add_rvalue_reference_t<T2>> {};

struct Foo {};

template <class T>
constexpr void test_add_lvalue_reference_t() noexcept {
    assert_add_lvalue_ref_t<T&, T> a1{};
    assert_add_lvalue_ref_t<T&, T&> a2{};
    assert_add_lvalue_ref_t<T&, T&&> a3{};

    assert_add_lvalue_ref_t<const T&, const T> a4{};
    assert_add_lvalue_ref_t<const T&, const T&> a5{};
    assert_add_lvalue_ref_t<const T&, const T&&> a6{};

    assert_add_lvalue_ref_t<volatile T&, volatile T> a7{};
    assert_add_lvalue_ref_t<volatile T&, volatile T&> a8{};
    assert_add_lvalue_ref_t<volatile T&, volatile T&&> a9{};

    assert_add_lvalue_ref_t<const volatile T&, const volatile T> a10{};
    assert_add_lvalue_ref_t<const volatile T&, const volatile T&> a11{};
    assert_add_lvalue_ref_t<const volatile T&, const volatile T&&> a12{};
}
template <class T>
constexpr void test_add_rvalue_reference_t() noexcept {
    assert_add_rvalue_ref_t<T&&, T> a1{};
    assert_add_rvalue_ref_t<T&&, T&> a2{};
    assert_add_rvalue_ref_t<T&&, T&&> a3{};

    assert_add_rvalue_ref_t<const T&&, const T> a4{};
    assert_add_rvalue_ref_t<const T&&, const T&> a5{};
    assert_add_rvalue_ref_t<const T&&, const T&&> a6{};

    assert_add_rvalue_ref_t<volatile T&&, volatile T> a7{};
    assert_add_rvalue_ref_t<volatile T&&, volatile T&> a8{};
    assert_add_rvalue_ref_t<volatile T&&, volatile T&&> a9{};

    assert_add_rvalue_ref_t<const volatile T&&, const volatile T> a10{};
    assert_add_rvalue_ref_t<const volatile T&&, const volatile T&> a11{};
    assert_add_rvalue_ref_t<const volatile T&&, const volatile T&&> a12{};
}

template <class T>
constexpr void _test_add_reference() noexcept {
    test_add_lvalue_reference_t<T>();
    test_add_rvalue_reference_t<T>();
}
template <class T>
constexpr void test_add_reference() noexcept {
    _test_add_reference<T>();
    _test_add_reference<T*>();
    _test_add_reference<T Foo::*>();
    _test_add_reference<T (Foo::*)()>();
}
int main() {
    test_add_reference<char>();
    test_add_reference<float>();
    test_add_reference<Foo>();

    _test_add_reference<void*>();
    _test_add_reference<void (*)()>();
    _test_add_reference<int Foo::*>();
    _test_add_reference<int (Foo::*)()>();
}
