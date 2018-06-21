#ifndef __nobodyxu_concept_check_detector_core_HPP__
# define __nobodyxu_concept_check_detector_core_HPP__

# include "void_t.hpp"
# include "nonsuch.hpp"
# include "integral_constant.hpp"

namespace nxwheels::concept_check::impl {
template <class Default, class always_void, template <class...> class op, class ...Ts>
struct detector: false_type {
    using result_type = Default;
};

template <class Default, template <class...> class op, class ...Ts>
struct detector<Default, void_t<op<Ts...>>, op, Ts...>: true_type {
    using result_type = op<Ts...>;
};
} /* nxwheels::concept_check::impl */

namespace nxwheels::concept_check {
template <template <class...> class op, class ...Ts>
using detector_t = impl::detector<nonsuch, void, op, Ts...>;

template <template <class...> class op, class ...Ts>
using is_detected = impl::detector<nonsuch, void, op, Ts...>;

template <template <class...> class op, class ...Ts>
constexpr const static inline bool is_detected_v = detector_t<op, Ts...>::value;

template <template <class...> class op, class ...Ts>
using detected_t = typename detector_t<op, Ts...>::result_type;

template <class Default, template <class...> class op, class ...Ts>
using detected_or_t = typename impl::detector<Default, void, op, Ts...>::result_type;
template <class Default, template <class...> class op, class ...Ts>
struct detected_or {
    typedef detected_or_t<Default, op, Ts...> type;
};
} /* nxwheels::concept_check */
#endif
