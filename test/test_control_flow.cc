#include "../include/concepts/is_same.hpp"
#include "../include/control_flow.hpp"
using namespace nxwheels;

struct ft: false_type {};
struct tt: true_type {};

template <class T>
using as_origin = T;
int main() {
    // Test if_t.
    assert_same<if_t<0, int, char>, char>();
    assert_same<if_t<1, int, char>, int>();

    assert_same<if_t<0, delay<as_origin, int>, char>, char>();
    assert_same<if_t<1, char, delay<as_origin, int>>, char>();

    assert_same<if_t<0, delay<as_origin, int>, delay<as_origin, char>>, char>();
    assert_same<if_t<1, delay<as_origin, char>, delay<as_origin, int>>, char>();

    // Test conjunction_t.
    assert_same<conjunction_t<>, true_type>();
    assert_same<conjunction_t<ft>, ft>();
    assert_same<conjunction_t<false_type, ft, tt>, false_type>();
    assert_same<conjunction_t<true_type, tt, tt>, tt>();

    // Test disjunction_t.
    assert_same<disjunction_t<>, false_type>();
    assert_same<disjunction_t<ft>, ft>();
    assert_same<disjunction_t<false_type, ft, tt>, tt>();

    // Test else_if_t.
    assert_same<
        else_if_t<
            branch<false, void>,
            branch<true, int>
        >,
    int>();
    assert_same<
        else_if_t<
            branch<false, void>,
            branch<false, void>,
            branch<false, void>
        >,
    void>();
    assert_same<else_if_t<>, false_type>();
}
