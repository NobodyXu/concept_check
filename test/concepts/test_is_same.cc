#include "../../include/concepts/is_same.hpp"
using namespace nxwheels;

int main() {
    assert_not_same_type<>();
    assert_not_same_type<int>();
    assert_not_same_type<int, char>();
    assert_same_type<int, int>();
    assert_same_type<int, int, int>();//3
    assert_same_type<int, int, int, int>();//4
    assert_same_type<int, int, int, int, int>();//5
    assert_same_type<int, int, int, int, int, int>();//6
    assert_same_type<int, int, int, int, int, int, int>();//7
    assert_same_type<int, int, int, int, int, int, int, int>();//8
    assert_same_type<int, int, int, int, int, int, int, int, int>();//9
    assert_same_type<int, int, int, int, int, int, int, int, int, int>();//10
    assert_same_type<int, int, int, int, int, int, int, int, int, int, int>();//11
}
