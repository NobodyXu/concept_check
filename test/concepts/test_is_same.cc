#include "../../include/concepts/is_same.hpp"
using namespace nxwheels;

int main() {
    assert_not_same_type<>();

    assert_not_same_type<int>();

    assert_not_same_type<int, char>();
    assert_same_type<int, int>();

    assert_not_same_type<int, char, char>();
    assert_same_type<int, int, int>();//3

    assert_not_same_type<int, char, char, char>();
    assert_same_type<int, int, int, int>();//4
}
