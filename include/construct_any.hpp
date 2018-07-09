#ifndef __nobodyxu_concept_check_construct_any_HPP__
# define __nobodyxu_concept_check_construct_any_HPP__

namespace nxwheels {
struct construct_any {
    template <class T> operator T () const noexcept;
};
} /* nxwheels */
#endif
