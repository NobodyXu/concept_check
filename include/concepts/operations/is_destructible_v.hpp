#ifndef __nobodyxu_concept_check_concepts_operations_is_destructible_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_destructible_v_HPP__
# include "../../detector_core.hpp"
# include "../../utility.hpp"
namespace nxwheels::destructible_impl {
template <class T> using destroy_t = decltype(declval<T>().~T(), int{});
} /* nxwheels::destructible_impl */
namespace nxwheels {
template <class T> constexpr const static inline bool is_destructible_v = is_detected_v<destructible_impl::destroy_t, T>;

template <class T> constexpr const static inline bool is_nothrow_destructible_impl_v = noexcept( declval<T>().~T() );
template <class T> constexpr const static inline bool is_nothrow_destructible_v = []{
    if constexpr(is_destructible_v<T>)
        return is_nothrow_destructible_impl_v<T>;
    else
        return false;
}();
} /* nxwheels */
#endif
