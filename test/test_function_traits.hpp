#include "../src/function_traits.hpp"
#include "../src/concepts/is_same.hpp"
using namespace nxwheels::concept_check;

template <bool is_const_qualified,
          bool is_volatile_qualified,
          bool is_lvalue_reference_qualified,
          bool is_rvalue_reference_qualified,
          class T,
          bool is_noexcept = false,
          class add_pointer = T>
constexpr void _assert_function_traits() noexcept {
    typedef function_traits<T> func_t;

    static_assert(is_function_v<T>);

    static_assert(func_t::is_const_qualified_v == is_const_qualified);
    static_assert(func_t::is_volatile_qualified_v == is_volatile_qualified);
    static_assert(func_t::is_lvalue_reference_qualified_v == is_lvalue_reference_qualified);
    static_assert(func_t::is_rvalue_reference_qualified_v == is_rvalue_reference_qualified);
    static_assert(func_t::is_noexcept_qualified_v == is_noexcept);

    assert_same<typename func_t::add_pointer_t, add_pointer>();
}

template <class R, class ...Args>
constexpr void assert_function_traits() noexcept {
    _assert_function_traits<false, false, false, false, R (Args...), false, R (*)(Args...)>();
    _assert_function_traits<false, false, false, false, R (Args...) noexcept, true, R (*)(Args...) noexcept>();

    _assert_function_traits<true, false, false, false, R (Args...) const>();
    _assert_function_traits<true, false, true, false, R (Args...) const &>();
    _assert_function_traits<true, false, false, true, R (Args...) const &&>();

    _assert_function_traits<true, false, false, false, R (Args...) const noexcept, true>();
    _assert_function_traits<true, false, true, false, R (Args...) const & noexcept, true>();
    _assert_function_traits<true, false, false, true, R (Args...) const && noexcept, true>();

    _assert_function_traits<false, true, false, false, R (Args...) volatile>();
    _assert_function_traits<false, true, true, false, R (Args...) volatile &>();
    _assert_function_traits<false, true, false, true, R (Args...) volatile &&>();

    _assert_function_traits<false, true, false, false, R (Args...) volatile noexcept, true>();
    _assert_function_traits<false, true, true, false, R (Args...) volatile & noexcept, true>();
    _assert_function_traits<false, true, false, true, R (Args...) volatile && noexcept, true>();

    _assert_function_traits<false, false, true, false, R (Args...) &>();
    _assert_function_traits<false, false, false, true, R (Args...) &&>();

    _assert_function_traits<false, false, true, false, R (Args...) & noexcept, true>();
    _assert_function_traits<false, false, false, true, R (Args...) && noexcept, true>();

    _assert_function_traits<true, true, false, false, R (Args...) const volatile>();
    _assert_function_traits<true, true, true, false, R (Args...) const volatile &>();
    _assert_function_traits<true, true, false, true, R (Args...) const volatile &&>();

    _assert_function_traits<true, true, false, false, R (Args...) const volatile noexcept, true>();
    _assert_function_traits<true, true, true, false, R (Args...) const volatile & noexcept, true>();
    _assert_function_traits<true, true, false, true, R (Args...) const volatile && noexcept, true>();
}
int main() {
    static_assert(!is_function_v<int>);

    assert_function_traits<int>();
}
