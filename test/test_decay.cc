#include "../src/decay.hpp"
#include "../src/concepts/is_same.hpp"
using namespace nxwheels::concept_check;

int main() {
    // Test decay_t against the 3 rules of decay_t.
    // Rule 1
    typedef int array[10];
    typedef int array2[10][10];
    assert_same<decay_t<array>, int*>();
    assert_same<decay_t<array&>, int*>();
    assert_same<decay_t<array&&>, int*>();
    assert_same<decay_t<array2>, array*>();
    assert_same<decay_t<array2&&>, array*>();
    // Rule 2
    assert_same<decay_t<int (void)>, int (*)(void)>();
    assert_same<decay_t<int (&)(void)>, int (*)(void)>();
    // Rule 3
    assert_same<decay_t<int>, int>();
    assert_same<decay_t<const int>, int>();
    assert_same<decay_t<volatile int>, int>();
    assert_same<decay_t<const volatile int>, int>();

    assert_same<decay_t<int&>, int>();
    assert_same<decay_t<int&&>, int>();

    assert_same<decay_t<const volatile int &&>, int>();
}
