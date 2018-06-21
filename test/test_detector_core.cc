#include <utility>
#include "../src/is_same.hpp"
#include "../src/detector_core.hpp"
using namespace nxwheels::concept_check;

template <class T>
using dereference = decltype(*std::declval<T>());
int main() {
    // Test detector_t.
    static_assert(detector_t<dereference, int*>{}());
    static_assert(!detector_t<dereference, int>{}());
    assert_detected<dereference, int*>();
    assert_not_detected<dereference, int>();

    // Test is_detected.
    static_assert(is_detected<dereference, int*>{}());
    static_assert(!is_detected<dereference, int>{}());

    // Test is_detected_v.
    static_assert(is_detected_v<dereference, int*>);
    static_assert(!is_detected_v<dereference, int>);

    // Test detected_t.
    static_assert(std::is_same<detected_t<dereference, int>, nonsuch>{}());
    static_assert(std::is_same<detected_t<dereference, int*>, decltype(*std::declval<int*>())>{}());

    // Text detected_or_t.
    assert_same<detected_or_t<void, dereference, int>, void>();
    assert_same<detected_or_t<void, dereference, int*>, int&>();
}
