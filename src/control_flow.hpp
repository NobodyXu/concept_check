/*!
 * This file contains control flows for template meta programming.
 * Inorder to be consistent with ```if```, ```else``` and other control flow statement used in normal programming, but not conflict with C++ standard
 * names, an underscore will be inserted before the original class name.
 */
#ifndef __nobodyxu_concept_check_control_flow_HPP__
# define __nobodyxu_concept_check_control_flow_HPP__
# include "detector_core.hpp"
namespace nxwheels::concept_check {
template <bool condition, class True, class False>
struct _if {
    typedef True  type;
};
template <class True, class False>
struct _if<0, True, False> {
    typedef False type;
};
template <bool condition, class True, class False>
using if_t = typename _if<condition, True, False>::type;
} /* nxwheels::concept_check */
#endif
