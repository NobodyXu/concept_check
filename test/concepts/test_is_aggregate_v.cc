#include "../../src/concepts/is_aggregate_v.hpp"
using namespace nxwheels::concept_check;

struct Nonaggregate {
    int i;
    Nonaggregate() {}
};

struct Aggregate {
    int i;
    char c;
};

int main() {
    static_assert(!is_aggregate_v<Nonaggregate>);
    static_assert(!is_aggregate_v<int>);

    static_assert(is_aggregate_v<Aggregate>);
    static_assert(is_aggregate_v<Aggregate[]>);
}
