#include "../../src/concepts/is_array.hpp"
using namespace nxwheels::concept_check;

int main() {
    static_assert(!is_array_v<int>);
    static_assert(is_array_v<int[]>);
    static_assert(is_array_v<int[111]>);

    {
        using type = int [111];
        static_assert(is_array_v<type[]>);
    }
    static_assert(is_array_v<int[111][222]>);
}
