#ifndef __nobodyxu_concept_check_decay_t_HPP__
# define __nobodyxu_concept_check_decay_t_HPP__

# include "utility.hpp"
# include "function_traits.hpp"

namespace nxwheels::concept_check::decay_impl {
template <class T, bool _is_function = is_function_v<T>>
struct auto_decay {
    auto operator () () noexcept {
        return declval<T>();
    }

   constexpr const static inline auto f = [] { return declval<T>(); };
    using type = decltype( f() );
};
template <class T>
struct auto_decay<T, true> {
    using type = typename function_traits<T>::add_pointer_t;
};
} /* nxwheels::concept_check::decay_impl */

namespace nxwheels::concept_check {
//template <class T> using decay_t = decltype( decay_impl::auto_decay< remove_reference_t<T> >{}() );
template <class T> using decay_t = typename decay_impl::auto_decay<T>::type;
} /* nxwheels::concept_check */
#endif