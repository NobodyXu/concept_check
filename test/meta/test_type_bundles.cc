#include <tuple>
namespace test {
#include "../../src/meta/type_bundles.hpp"
using namespace nxwheels::concept_check::meta;
} /* test */

int main() {
    using type_bundles_test_t = test::type_bundles_t<std::tuple<int, int>>;
    static_assert(std::is_same<type_bundles_test_t, test::type_bundles<int, int>>{}());
    static_assert(std::is_same<typename type_bundles_test_t::cast_to<std::tuple>, std::tuple<int, int>>{}());

    static_assert(type_bundles_test_t::value == 2);
    static_assert(std::is_same<test::type_bundles_element_t<0, type_bundles_test_t>, int>{}());
}
