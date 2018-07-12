#ifndef __nobodyxu_concept_check_partial_apply_HPP__
# define __nobodyxu_concept_check_partial_apply_HPP__

namespace nxwheels {
template <template <class...> class Op, class ...Ts>
struct partial_apply {
    template <class ...Args> using type = Op<Ts..., Args...>;
};
# define PARTIAL_APPLY_T(OP, ...) partial_apply<OP, ##__VA_ARGS__>::template type
} /* nxwheels */
#endif
