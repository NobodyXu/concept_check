#ifndef __nobodyxu_concept_check_decay_HPP__
# define __nobodyxu_concept_check_decay_HPP__

# include "utility.hpp"

namespace nxwheels::concept_check::decay_impl {
template <class T>
struct auto_decay {
    auto operator () () noexcept {
        return declval<T>();
    }
};
} /* nxwheels::concept_check::decay_impl */

namespace nxwheels::concept_check {
template <class T> using decay_t = decltype( (decl_as<decay_impl::auto_decay< T >>())() );
} /* nxwheels::concept_check */
#endif
