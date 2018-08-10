#include <type_traits>
#include "../include/type_tuple.hpp"
using namespace nxwheels;

int main() {
    // Test type_tuple::size.
    static_assert(type_tuple<int, int, int, int>::size == 4);

    // Test get_type_t.
    static_assert(std::is_same<get_type_t<0, type_tuple<char, long, unsigned, int>>, char>{}());
    static_assert(std::is_same<get_type_t<3, type_tuple<char, long, unsigned, int>>, int>{}());
}
