#include <type_traits>
#include "../src/control_flow.hpp"
using namespace nxwheels::concept_check;

struct ft: std::false_type {};
struct tt: std::true_type {};
int main() {
    // Test if_t.
    static_assert(std::is_same<if_t<0, int, char>, char>{}());
    static_assert(std::is_same<if_t<1, int, char>, int>{}());

    // Test disjunction_t.
    static_assert(std::is_same<disjunction_t<std::false_type, ft, tt>, tt>{}());
    static_assert(std::is_same<disjunction_t<>, false_type>{}());
    static_assert(std::is_same<disjunction_t<ft>, ft>{}());

    // Test else_if_t.
    static_assert(std::is_same<else_if_t<branch<false, void>,
                            branch<true, int>
    >, int>{}());
}
