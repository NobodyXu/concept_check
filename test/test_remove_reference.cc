#include <type_traits>
#include "../include/remove_reference.hpp"
using namespace nxwheels;

struct Foo {};

template <class T>
constexpr void test_remove_reference_t() noexcept {
    static_assert(std::is_same<remove_reference_t<T>, T>{}());
    static_assert(std::is_same<remove_reference_t<T&>, T>{}());
    static_assert(std::is_same<remove_reference_t<T&&>, T>{}());

    static_assert(std::is_same<remove_reference_t<const T>, const T>{}());
    static_assert(std::is_same<remove_reference_t<const T&>, const T>{}());
    static_assert(std::is_same<remove_reference_t<const T&&>, const T>{}());

    static_assert(std::is_same<remove_reference_t<volatile T>, volatile T>{}());
    static_assert(std::is_same<remove_reference_t<volatile T&>, volatile T>{}());
    static_assert(std::is_same<remove_reference_t<volatile T&&>, volatile T>{}());

    static_assert(std::is_same<remove_reference_t<const volatile T>, const volatile T>{}());
    static_assert(std::is_same<remove_reference_t<const volatile T&>, const volatile T>{}());
    static_assert(std::is_same<remove_reference_t<const volatile T&&>, const volatile T>{}());
}
template <class T>
constexpr void test() noexcept {
    test_remove_reference_t<T>();
    test_remove_reference_t<T*>();
    test_remove_reference_t<T Foo::*>();
    test_remove_reference_t<T (Foo::*)()>();
}
int main() {
    test<char>();
    test<int>();
    test<Foo>();
    test_remove_reference_t<void*>();
}
