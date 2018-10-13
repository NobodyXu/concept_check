#include "../../include/concepts/is_iterator_v.hpp"

#include <array>
#include <vector>
#include <forward_list>
#include <list>
#include <iterator>

using namespace nxwheels;

int main() {
    static_assert(!is_Iterator_v<int>);
    static_assert(!is_RandomAccessIterator_v<int>);

    // Input Iterator
    static_assert(is_InputIterator_v<std::istream_iterator<int>>);

    // Output Iterator
    static_assert(is_Iterator_v<std::back_insert_iterator<std::vector<int>>>);

    // Forward Iterator
    static_assert(is_mutable_ForwardIterator_v<decltype(std::forward_list<int>().begin())>);
    static_assert(is_const_ForwardIterator_v<decltype(std::forward_list<int>().cbegin())>);

    // Bidirectional Iterator
    static_assert(is_mutable_BidirectionalIterator_v<decltype(std::list<int>().begin())>);
    static_assert(is_const_BidirectionalIterator_v<decltype(std::list<int>().cbegin())>);

    // Random Access Iterator
    static_assert(is_mutable_RandomAccessIterator_v<int*>);
    static_assert(is_const_RandomAccessIterator_v<const int*>);

    static_assert(is_mutable_RandomAccessIterator_v<decltype(std::array<int, 10>().begin())>);
    static_assert(is_const_RandomAccessIterator_v<decltype(std::array<int, 10>().cbegin())>);

    static_assert(is_mutable_RandomAccessIterator_v<decltype(std::vector<int>().begin())>);
    static_assert(is_const_RandomAccessIterator_v<decltype(std::vector<int>().cbegin())>);
}
