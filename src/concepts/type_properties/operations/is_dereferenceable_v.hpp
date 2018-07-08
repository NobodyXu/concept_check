#ifndef __nobodyxu_concept_check_concepts_type_properties_operations_is_dereferenceable_v_HPP__
# define __nobodyxu_concept_check_concepts_type_properties_operations_is_dereferenceable_v_HPP__

# include "../../../detector_core.hpp"
# include "../../../utility.hpp"

namespace nxwheels::concept_check {
template <class T> using dereferenced_t = decltype( *declval<T>() );

template <class T> constexpr const static inline bool is_dereferenceable_v = is_detected_v<dereferenced_t, T>;

template <class T> constexpr const static inline bool _is_nothrow_dereferenceable_v = noexcept( *declval<T>() );
template <class T> constexpr const static inline bool is_nothrow_dereferenceable_v = []{
    if constexpr(is_dereferenceable_v<T>)
        return _is_nothrow_dereferenceable_v<T>;
    else
        return false;
}();
} /* nxwheels::concept_check */
#endif
