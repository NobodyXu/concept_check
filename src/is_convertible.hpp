#ifndef __nobodyxu_concept_check_is_convertible_HPP__
# define __nobodyxu_concept_check_is_convertible_HPP__
# include "integral_constant.hpp"
# include "is_same.hpp"
# include "utility.hpp"
# include "detector_core.hpp"
namespace nxwheels::concept_check {
template <class From, class To>
struct implict_convert_from_right_val_t {
    To operator () () {
        return declval<From>();
    }
};

template <class From, class To>
constexpr const static inline bool is_implicitly_convertible_v = is_detected_v<implict_convert_from_right_val_t, From, To>;
template <class From, class To>
struct is_implicitly_convertible: bool_constant<is_implicitly_convertible_v<From, To>> {};
} /* nxwheels::concept_check */
#endif
