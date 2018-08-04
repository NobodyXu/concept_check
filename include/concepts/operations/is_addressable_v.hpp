#ifndef __nobodyxu_concept_check_concepts_operations_is_addressable_v_HPP__
# define __nobodyxu_concept_check_concepts_operations_is_addressable_v_HPP__

# include "../../detector_core.hpp"
# include "../../utility.hpp"
# include "def_convenient_macros.hpp"

namespace nxwheels {
//DEF_UN_CHECK(address, &);
template <class T> using addressed_t = decltype( &declval<T>() );

template <class T> constexpr const static inline bool is_addressable_v = is_detected_v<addressed_t, T>;

template <class T> constexpr const static inline bool _is_nothrow_addressable_v = noexcept( &declval<T>() );
template <class T> constexpr const static inline bool is_nothrow_addressable_v = []{
    if constexpr(is_addressable_v<T>)
        return _is_nothrow_addressable_v<T>;
    else
        return false;
}();
} /* nxwheels */

# include "def_convenient_macros.hpp"

#endif
