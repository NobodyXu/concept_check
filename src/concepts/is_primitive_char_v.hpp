#ifndef __nobodyxu_concept_check_concepts_is_primitive_char_v_HPP__
# define __nobodyxu_concept_check_concepts_is_primitive_char_v_HPP__
namespace nxwheels::concept_check {
template <class T> constexpr const static inline bool is_primitive_char_v = false;

# define DEF_SP(type)\
template <>        constexpr const static inline bool is_primitive_char_v< type > = true

DEF_SP(char);
DEF_SP(char16_t);
DEF_SP(char32_t);
DEF_SP(wchar_t);

# undef DEF_SP
} /* nxwheels::concept_check */
#endif
