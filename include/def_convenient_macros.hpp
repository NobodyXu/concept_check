#ifndef   CONSTEXPR_GLOBAL_VAR
# if   __cplusplus == 201703L
#  define CONSTEXPR_GLOBAL_VAR constexpr const static inline
# elif __cplusplus == 201402L
#  define CONSTEXPR_GLOBAL_VAR constexpr const static
# endif
#endif

#ifndef  CONCEPT_T
# define CONCEPT_T CONSTEXPR_GLOBAL_VAR bool
#endif
