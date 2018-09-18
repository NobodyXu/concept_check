#include "../enable_if.hpp"

#include "../def_convenient_macros.hpp"


#ifndef TP1
# define TP1 template <class T>
#endif

#ifndef DEF_CONCEPT1
# define DEF_CONCEPT1 TP1 CONCEPT_T
#endif

#ifndef DEF_CHECK1
# define DEF_CHECK1(NAME) template <class T, class = enable_if_t< is_## NAME ##_v<std::remove_reference_t<T>> >> using NAME = T
#endif
