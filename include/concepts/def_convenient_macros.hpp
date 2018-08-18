#include <type_traits>

#ifndef VAR
# define VAR constexpr const static inline bool
#endif

#ifndef TP1
# define TP1 template <class T>
#endif

#ifndef DEF_CONCEPT1
# define DEF_CONCEPT1 TP1 VAR
#endif

#ifndef DEF_CHECK1
# define DEF_CHECK1(NAME) template <class T, class = std::enable_if_t<is_## NAME ##_v>> using NAME = T;
#endif
