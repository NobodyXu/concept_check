#include "../include/remove_pointer.hpp"
#include "../include/concepts/is_same.hpp"
using namespace nxwheels;

int main() {
    assert_same<remove_pointer_t<int>, int>();

    assert_same<remove_pointer_t<int*>, int>();
    assert_same<remove_pointer_t<int**>, int*>();

    assert_same<remove_pointer_t<int * const>, int>();
    assert_same<remove_pointer_t<int * const volatile>, int>();
}
