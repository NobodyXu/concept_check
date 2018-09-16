#include <type_traits>
#include "../include/detector_core.hpp"
using namespace nxwheels;

template <class T>
using dereference = decltype(*std::declval<T>());
int main() {
    // Test detector_t.
    static_assert(detector_t<dereference, int*>::value);
    static_assert(!detector_t<dereference, int>::value);

    // Test is_detected.
    static_assert(is_detected<dereference, int*>::value);
    static_assert(!is_detected<dereference, int>::value);

    // Test is_detected_v.
    static_assert(is_detected_v<dereference, int*>);
    static_assert(!is_detected_v<dereference, int>);

    // Test detected_t.
    static_assert(std::is_same<detected_t<dereference, int>, nonsuch>{}());
    static_assert(std::is_same<detected_t<dereference, int*>, decltype(*std::declval<int*>())>{}());

    // Text detected_or_t.
    static_assert(std::is_same<detected_or_t<void, dereference, int>, void>::value);
    static_assert(std::is_same<detected_or_t<void, dereference, int*>, int&>::value);
}
