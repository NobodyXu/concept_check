#include "../include/enable_if.hpp"
#include "../include/integral_constant.hpp"
using namespace nxwheels;

template <class T, class = enable_if_t<T::value>>
void F(T) {}

int main() {
    F(true_type{});
    F(false_type{});
}
