#include <type_traits>
#include "../include/type_tuple.hpp"
using namespace nxwheels;

template <class T1, class T2, class T3, class T4>
struct test_applicant {
    static_assert(std::is_same<T1, char>{}());
    static_assert(std::is_same<T2, long>{}());
    static_assert(std::is_same<T3, unsigned>{}());
    static_assert(std::is_same<T4, int>{}());
};

int main() {
    // Test type_tuple::size.
    static_assert(type_tuple<int, int, int, int>::size == 4);

    // Test template type_tuple::applied_t.
    {

        using type = type_tuple<char, long, unsigned, int>::applied_t<test_applicant>;
        static_assert(std::is_same<type, test_applicant<char, long, unsigned, int>>{}());
        type{};
        //type_tuple<char, int, unsigned, int>::applied_t<test_applicant>{};

    }

    // Test apply_to_t.
    {

        using type = apply_to_t<test_applicant, type_tuple<char, long, unsigned, int>>;
        static_assert(std::is_same<type, test_applicant<char, long, unsigned, int>>{}());
        type{};
        //type_tuple<char, int, unsigned, int>::applied_t<test_applicant>{};

    }

    // Test get_type_t.
    static_assert(std::is_same<get_type_t<0, type_tuple<char, long, unsigned, int>>, char>{}());
    static_assert(std::is_same<get_type_t<3, type_tuple<char, long, unsigned, int>>, int>{}());

}
