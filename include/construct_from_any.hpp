#ifndef  __nobodyxu_concept_check_construct_from_any_HPP__
# define __nobodyxu_concept_check_construct_from_any_HPP__

# include "nonsuch.hpp"

namespace nxwheels {
/*!
 * construct_from_any can construct from any type except nonsuch.
 */
struct construct_from_any {
    template <class ...Args>
    constexpr construct_from_any(Args &&...) noexcept {}

    construct_from_any(nonsuch) = delete;
};
} /* nxwheels */
#endif
