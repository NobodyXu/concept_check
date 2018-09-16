#ifndef __nobodyxu_concept_check_type_tuple_HPP__
# define __nobodyxu_concept_check_type_tuple_HPP__

# include "enable_if.hpp"
# include "usefull_types.hpp"

namespace nxwheels {
/*!
 * type_tuple only served as a storage of type during comliation, it should never be used during runtime.
 */
template <class ...Args>
struct type_tuple {
    constexpr const static inline size_t size = sizeof...(Args);

    template <template <class...> class applicant> using applied_t = applicant<Args...>;
};

template <size_t index, class T> struct get_type_impl;
// The loop
template <size_t index, class T, class ...Args>
struct get_type_impl<index, type_tuple<T, Args...>> { using type = typename get_type_impl<index - 1, type_tuple<Args...>>::type; };
// The end of loop.
template <class T, class ...Args>
struct get_type_impl<0, type_tuple<T, Args...>> { using type = T; };

template <size_t index, class T> using get_type_t = enable_if_t<index < T::size, typename get_type_impl<index, T>::type>;

template <template <class...> class, class> struct apply_to;
template <template <class...> class applicant, class ...Args>
struct apply_to<applicant, type_tuple<Args...>> {
    using type = applicant<Args...>;
};

template <template <class...> class applicant, class Source> using apply_to_t = typename apply_to<applicant, Source>::type;
} /* nxwheels */
#endif
