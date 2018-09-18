#ifndef   CONCEPT_T
# if   __cplusplus == 201703L
#  define CONCEPT_T constexpr const static inline
# elif __cplusplus == 201402L
#  define CONCEPT_T constexpr const static
# endif
#endif
