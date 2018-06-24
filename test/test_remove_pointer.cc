#include "../src/remove_pointer.hpp"
#include "../src/concepts/is_same.hpp"
using namespace nxwheels::concept_check;

int main() {
    assert_same<remove_pointer_t<int>, int>();

    assert_same<remove_pointer_t<int*>, int>();
    assert_same<remove_pointer_t<int**>, int*>();

    assert_same<remove_pointer_t<int * const>, int>();
    assert_same<remove_pointer_t<int * const volatile>, int>();
}
