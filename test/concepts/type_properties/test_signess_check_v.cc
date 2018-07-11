#include "../../../include/concepts/type_properties/signess_check_v.hpp"
using namespace nxwheels;

int main() {
    static_assert(!is_signed_v<bool>);

    static_assert(is_signed_v<int>);
    static_assert(is_signed_v<char>);
    static_assert(is_signed_v<float>);
}
