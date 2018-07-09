#include "../include/remove_extent.hpp"
#include "../include/concepts/is_same.hpp"
using namespace nxwheels;

int main() {
    // Test remove_extent_t.
    assert_same<remove_extent_t<int>, int>();

    assert_same<remove_extent_t<int[]>, int>();
    assert_same<remove_extent_t<int[2]>, int>();
    assert_same<remove_extent_t<const volatile int[2]>, const volatile int>();
    {
        using type = int [2];
        assert_same<remove_extent_t<type[2]>, type>();
    }

    // Test remove_all_extent_t.
    assert_same<remove_all_extent_t<int>, int>();

    assert_same<remove_all_extent_t<int[]>, int>();
    assert_same<remove_all_extent_t<int[2]>, int>();
    assert_same<remove_all_extent_t<const volatile int[2]>, const volatile int>();
    {
        using type = int [2];
        assert_same<remove_all_extent_t<type[2]>, int>();
    }
}
