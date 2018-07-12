#include "../include/partial_apply.hpp"
using namespace nxwheels;

template <class ...Ts> struct A {};
template <template <class...> class Op> using apply_int = Op<int>;

int main() {
    using type = apply_int<PARTIAL_APPLY_T(A)>;
}
