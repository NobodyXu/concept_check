#include "../../../include/concepts/operations/is_assignable_v.hpp"
using namespace nxwheels;

struct nonmovable {
    nonmovable& operator = (const nonmovable&) = delete;
    nonmovable& operator = (nonmovable&&) = delete;
};
struct cpable {};
struct movable {
    movable& operator = (const movable&) = delete;
    movable& operator = (movable&&) = default;
};
struct usrdef_cpable {
    usrdef_cpable& operator = (const usrdef_cpable&) { return *this; }
};
struct usrdef_movable {
    usrdef_movable& operator = (usrdef_movable&&) { return *this; }
};
struct nothrow_usrdef_cpable {
    nothrow_usrdef_cpable& operator = (const nothrow_usrdef_cpable&) noexcept { return *this; }
};
struct nothrow_usrdef_movable {
    nothrow_usrdef_movable& operator = (nothrow_usrdef_movable&&) noexcept { return *this; }
};

int main() {
    // Test has_assignment_v.
    static_assert(!has_assignment_v<nonmovable, const nonmovable&>);
    static_assert(!has_assignment_v<nonmovable, nonmovable>);

    static_assert(has_assignment_v<int&, int>);
    static_assert(has_assignment_v<cpable, const cpable&>);
    static_assert(has_assignment_v<cpable, cpable>);

    static_assert(has_assignment_v<usrdef_cpable, const usrdef_cpable&>);
    static_assert(has_assignment_v<usrdef_cpable, usrdef_cpable>);
    static_assert(has_assignment_v<usrdef_movable, usrdef_movable>);

    static_assert(has_assignment_v<nothrow_usrdef_cpable, const nothrow_usrdef_cpable&>);
    static_assert(has_assignment_v<nothrow_usrdef_cpable, nothrow_usrdef_cpable>);
    static_assert(has_assignment_v<nothrow_usrdef_movable, nothrow_usrdef_movable>);

    static_assert(has_assignment_v<movable, movable>);

    // Test has_nothrow_assignment_v.
    static_assert(!has_nothrow_assignment_v<nonmovable, const nonmovable&>);
    static_assert(!has_nothrow_assignment_v<nonmovable, nonmovable>);
    static_assert(!has_nothrow_assignment_v<usrdef_cpable, const usrdef_cpable&>);
    static_assert(!has_nothrow_assignment_v<usrdef_cpable, usrdef_cpable>);

    static_assert(has_nothrow_assignment_v<int&, int>);
    static_assert(has_nothrow_assignment_v<cpable, const cpable&>);
    static_assert(has_nothrow_assignment_v<cpable, cpable>);
    static_assert(has_nothrow_assignment_v<movable, movable>);

    static_assert(has_nothrow_assignment_v<nothrow_usrdef_cpable, const nothrow_usrdef_cpable&>);
    static_assert(has_nothrow_assignment_v<nothrow_usrdef_cpable, nothrow_usrdef_cpable>);
    static_assert(has_nothrow_assignment_v<nothrow_usrdef_movable, nothrow_usrdef_movable>);

    // Test is_std_conformant_assignable_v.
    static_assert(!is_std_conformant_assignable_v<nonmovable, const nonmovable&>);
    static_assert(!is_std_conformant_assignable_v<nonmovable, nonmovable>);

    static_assert(is_std_conformant_assignable_v<int&, int>);
    static_assert(is_std_conformant_assignable_v<cpable, const cpable&>);
    static_assert(is_std_conformant_assignable_v<cpable, cpable>);

    static_assert(is_std_conformant_assignable_v<usrdef_cpable, const usrdef_cpable&>);
    static_assert(is_std_conformant_assignable_v<usrdef_cpable, usrdef_cpable>);
    static_assert(is_std_conformant_assignable_v<usrdef_movable, usrdef_movable>);

    static_assert(is_std_conformant_assignable_v<nothrow_usrdef_cpable, const nothrow_usrdef_cpable&>);
    static_assert(is_std_conformant_assignable_v<nothrow_usrdef_cpable, nothrow_usrdef_cpable>);
    static_assert(is_std_conformant_assignable_v<nothrow_usrdef_movable, nothrow_usrdef_movable>);

    static_assert(is_std_conformant_assignable_v<movable, movable>);

    // Test is_nothrow_std_conformant_assignable_v.
    static_assert(!is_nothrow_std_conformant_assignable_v<nonmovable, const nonmovable&>);
    static_assert(!is_nothrow_std_conformant_assignable_v<nonmovable, nonmovable>);
    static_assert(!is_nothrow_std_conformant_assignable_v<usrdef_cpable, const usrdef_cpable&>);
    static_assert(!is_nothrow_std_conformant_assignable_v<usrdef_cpable, usrdef_cpable>);

    static_assert(is_nothrow_std_conformant_assignable_v<int&, int>);
    static_assert(is_nothrow_std_conformant_assignable_v<cpable, const cpable&>);
    static_assert(is_nothrow_std_conformant_assignable_v<cpable, cpable>);
    static_assert(is_nothrow_std_conformant_assignable_v<movable, movable>);

    static_assert(is_nothrow_std_conformant_assignable_v<nothrow_usrdef_cpable, const nothrow_usrdef_cpable&>);
    static_assert(is_nothrow_std_conformant_assignable_v<nothrow_usrdef_cpable, nothrow_usrdef_cpable>);
    static_assert(is_nothrow_std_conformant_assignable_v<nothrow_usrdef_movable, nothrow_usrdef_movable>);
}
