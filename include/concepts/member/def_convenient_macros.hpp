#include "../../detector_core.hpp"
#include "../../def_convenient_macros.hpp"

#ifndef  DEF_MEMBER_TYPE_CHECK

# define DEF_MEMBER_TYPE_CHECK(TYPE)                                                    \
template <class T> using member_type_## TYPE ##_t = typename T:: TYPE;                  \
template <class T, class Default = nonsuch>                                             \
using member_type_## TYPE ##_or_t = detected_or_t<Default, member_type_## TYPE ##_t, T>;\
template <class T>                                                                      \
CONCEPT_T has_member_type_## TYPE ##_v = is_detected_v<member_type_## TYPE ##_t, T>

#endif
