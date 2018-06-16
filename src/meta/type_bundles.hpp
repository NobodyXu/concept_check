#ifndef __nobodyxu_wheels_meta_type_bundles_HPP__
# define __nobodyxu_wheels_meta_type_bundles_HPP__

namespace nxwheels::concept_check::meta::impl {
template <class T> using pointer = T*;
} /* nxwheels::concept_check::meta::impl */

# include <type_traits>
namespace nxwheels::concept_check::meta {
template <class ...Types>
struct type_bundles: std::integral_constant<std::size_t, sizeof...(Types)> {
    template <template <class...> class Tuple>
    constexpr type_bundles(Tuple<Types...>*) {}

    template <template <class...> class Tuple>
    using cast_to = Tuple<Types...>;
};

template <template <class...> class Tuple, class ...Types>
type_bundles(Tuple<Types...>*) -> type_bundles<Types...>;

template <class Tuple>
using type_bundles_t = decltype(type_bundles(impl::pointer<Tuple>{}));

template <std::size_t N, class T>
struct type_bundles_element;

template <std::size_t N, class T, class ...Types>
struct type_bundles_element<N, type_bundles<T, Types...>>: type_bundles_element<N - 1, type_bundles<Types...>> {};

template <class T, class ...Types>
struct type_bundles_element<0, type_bundles<T, Types...>> {
    using type = T;
};

template <std::size_t N, class T> using type_bundles_element_t = typename type_bundles_element<N, T>::type;
} /* nxwheels::concept_check::meta */
#endif
