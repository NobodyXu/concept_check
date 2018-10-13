#include "../../include/concepts/is_iterator_v.hpp"

#include <array>
#include <vector>
#include <forward_list>
#include <list>
#include <iterator>

using namespace nxwheels;

int main() {
    using InputIterator_t  = std::istream_iterator<int>;
    using OutputIterator_t = std::back_insert_iterator<std::vector<int>>;

    using const_ForwardIterator_t   = decltype(std::forward_list<int>().cbegin());
    using mutable_ForwardIterator_t = decltype(std::forward_list<int>().begin());

    using const_BidirectionalIterator_t   = decltype(std::list<int>().cbegin());
    using mutable_BidirectionalIterator_t = decltype(std::list<int>().begin());

    static_assert(!is_Iterator_v<int>);

    // Input Iterator
    static_assert(is_InputIterator_v<InputIterator_t>);

    // Output Iterator
    static_assert(is_Iterator_v<OutputIterator_t>);

    // Forward Iterator
    {
        static_assert(!is_ForwardIterator_v<InputIterator_t>);
        static_assert(!is_ForwardIterator_v<OutputIterator_t>);

        static_assert(is_mutable_ForwardIterator_v<mutable_ForwardIterator_t>);
        static_assert(is_const_ForwardIterator_v<const_ForwardIterator_t>);
    }

    // Bidirectional Iterator
    {
        static_assert(!is_BidirectionalIterator_v<mutable_ForwardIterator_t>);

        static_assert(is_mutable_BidirectionalIterator_v<mutable_BidirectionalIterator_t>);
        static_assert(is_const_BidirectionalIterator_v<const_BidirectionalIterator_t>);
    }

    // Random Access Iterator
    {
        static_assert(!is_RandomAccessIterator_v<int>);
        static_assert(!is_RandomAccessIterator_v<mutable_BidirectionalIterator_t>);

        static_assert(is_mutable_RandomAccessIterator_v<int*>);
        static_assert(is_const_RandomAccessIterator_v<const int*>);

        static_assert(is_mutable_RandomAccessIterator_v<decltype(std::vector<int>().begin())>);
        static_assert(is_const_RandomAccessIterator_v<decltype(std::vector<int>().cbegin())>);
    }
}
