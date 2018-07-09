#include "../../include/concepts/is_null_pointer_v.hpp"
using namespace nxwheels;

int main() {
    static_assert(!is_null_pointer_v<int>);

    static_assert(is_null_pointer_v<decltype(nullptr)>);
}
