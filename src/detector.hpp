#ifndef __nobodyxu_concept_check_detector_HPP__
# define __nobodyxu_concept_check_detector_HPP__
# include "detector_core.hpp"
namespace nxwheels::concept_check {

/*
template< class Default, template<class...> class Op, class... Args >
using detected_or_t = typename detected_or<Default, Op, Args...>::type;
(library fundamentals TS v2)

template <class Expected, template<class...> class Op, class... Args>
using is_detected_exact = is_same<Expected, detected_t<Op, Args...>>;
(library fundamentals TS v2)

template <class Expected, template<class...> class Op, class... Args>
constexpr bool is_detected_exact_v = is_detected_exact<Expected, Op, Args...>::value;
(library fundamentals TS v2)

template <class To, template<class...> class Op, class... Args>
using is_detected_convertible = is_convertible<detected_t<Op, Args...>, To>;
(library fundamentals TS v2)

template <class To, template<class...> class Op, class... Args>
constexpr bool is_detected_convertible_v = is_detected_convertible<To, Op, Args...>::value;
(library fundamentals TS v2)
 */
} /* nxwheels::concept_check */
#endif
