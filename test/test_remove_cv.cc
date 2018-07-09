#include "../include/remove_cv.hpp"
#include "../include/concepts/is_same.hpp"
using namespace nxwheels;

int main() {
    assert_same<remove_const_t<int>, int>();
    assert_same<remove_const_t<const int>, int>();

    assert_same<remove_volatile_t<int>, int>();
    assert_same<remove_volatile_t<volatile int>, int>();

    assert_same<remove_cv_t<int>, int>();
    assert_same<remove_cv_t<volatile int>, int>();
    assert_same<remove_cv_t<const int>, int>();
    assert_same<remove_cv_t<const volatile int>, int>();
}
