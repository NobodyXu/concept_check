#include "../src/is_same.hpp"
#include "../src/delay.hpp"
using namespace nxwheels::concept_check;

template <class T>
using as_itself = T;
int main() {
    assert_same<evaluate_t<int>, int>();
    assert_same<evaluate_t<delay<as_itself, int>>, int>();
    assert_same<evaluate_t<delay<as_itself, delay<as_itself, int>>>, int>();
}
