# concept_check
This is a C++17 header-only concept check library.
[![Build Status](https://travis-ci.org/NobodyXu/concept_check.svg?branch=master)](https://travis-ci.org/NobodyXu/concept_check)

## Examples

```c++
#include <type_traits>
#include <concept_check/concepts/is_iterator_v.hpp>

// Example 1, with syntex like the concept check proposal.
template <class It>
void func1(nxwheels::RandomAccessIterator<It> &&) {}

func1(int{});// This fails
using pointer1 = int*;
func1(pointer1{});

// Example 2, a more straight forward example. It is equivalent with example 1.
template <class It>
auto func2(It &&) -> std::enable_if_t< is_Iterator_v<std::remove_reference_t<It>> > {}
```

## Goal of the library
I created this library due to my hate for the ugly and disturbed syntex of ```The Boost Concept Check library```. It forces you to use ```BOOST_CONCEPT_REQUIRES``` which requires you to put your return type into it, or use ```BOOST_CONCEPT_ASSERT```. What's more, the way to extend it is quite strange to me -- you create another class in many lines to check it.

This library is intended to be clear in syntex and reusable and let users have freedom on the style of their function.

## Structure of the repository.
This library is header-only, so the structure of this repository quite simple.

 1. Stuffs that facilitate writing concepts, like ```detector_core.hpp``` and ```utility.hpp``` are put under ```/include``` directly.
 2. Concepts are all put under ```/include/concepts/```.
 3. Concepts that check a particular operation or member of a type are put under ```/include/concepts/operations/``` and ```/include/concepts/member``` respectively.
 4. Tests are put in another dir named ```/test/``` and has the similar structure as ```/include/```.

## How to use the concepts in the library.
All concepts in this library are defined in ```is_NAME_v``` with a type alias ```NAME_t``` or ```NAME```(only in concepts/is_iterator_v.hpp) that automatically checks the concept. It is defined like this:

```c++
template <class T> constexpr const static inline bool is_Iterator_v = /* Use concepts in concepts/operations and concepts/member */;
template <class T, class = std::enable_if_t<is_Iterator_v< std::remove_reference_t<T> >>> using Iterator = T;
```

In order to make defining them eaiser, I use a lot of macro in concepts. Use of macros improve the readability dramatically, from being a total shit-like code to something very neat(Ex /include/concepts/operations/is_comparable_v.hpp).

Most of the oncepts under ```/include/concepts/operations/``` are intended to be able to work with reference, except ```is_arrowable_v.hpp```(Test op ```->```). This file contains hacks to work around the limit of ```detector idoms```, and cannot be used with reference or const/volatile qualified types.

## How this library works
Most of the concepts defined in this library use ```declval``` defined in ```/include/utility.hpp``` to "get" instance of a type in an unevaluated context and class template ```is_detected_v``` in ```/include/detector_core.hpp``` to check whether an expression is valid. ```is_detected_v``` is a library fundamentals TS v2 feature, you can find more description of it at [here](https://en.cppreference.com/w/cpp/experimental/is_detected). My detector is compliant to its API.

An example of how concept check works:

```c++
template <class T> using dereferenced_t = decltype(*declval<T>());
template <class T> constexpr const static inline bool is_dereferenceable_v = is_detected_v<dereferenced_t, T>;
template <class T> constexpr const static inline bool is_nothrow_dereferenceable_impl_v = noexcept(*declval<T>());
template <class T> constexpr const static inline bool is_nothrow_dereferenceable_v = []{
  if constexpr(is_dereferenceable_v<T>)
    return is_nothrow_dereferenceable_impl_v<T>;
  else
    return false;
}();
```

## Reason why some of the utility and concepts are rewriten here despite ```STL``` has defined them
 1. The code from ```libstdc++``` keep emitting nonsense errors(std::declval keep giving out errors due to a fail in static_assert that checks for use in evaluated context);
 2. They haven't got the feature I want(std::add_reference in ```libstdc++``` won't work correctly for ```int () &``` because that is a ```C++17``` feature);
 3. I don't want to have too much dependency on ```type_traits```(usefull_types.hpp, bool_constant.hpp and type_tuple.hpp) and I am still thinking of whether I should delete them and depent on ```STL``` or be more independent of it.
 4. My version of them have more features. Ex the ```/include/concepts/operations/is_constructible_v.hpp``` can not only check whether a type ```T``` can be [direct initialized](https://en.cppreference.com/w/cpp/language/direct_initialization) from ```Args...```, it can also check whether it is [list-initializable](https://en.cppreference.com/w/cpp/language/list_initialization) or initializer_list-initializable.

## Contribution
I welcome anyone to contribute to this repository, and you can find me on Github or by email(displayed in my personal details on Github). If you have an issue, post it on Github Issues and I will repond to you as soon as possible.

### Where to put the file?
 * Concepts check whether member type alias exist should be put under ```/include/concepts/member```;
 * Concepts cehck whether an operation on type is valid should be put under ```/include/concepts/operations```;
 * Concepts check whether a type statisfy combined concepts(concepts check more than 1 operations or member) like ```iterator``` should be put under ```/include/concepts/```.

### Requirements when writing code
 1. Use macros defined in ```def_convenient_macros.hpp``` in the current dir to simplify the process of defining concepts and define new ones in the file if necessary. **The new macros should be put into the ```def_convenient_macros.hpp``` in the current dir and a ```#undef``` should be put in the ```undef_convenient_macros.hpp``` in the current dir.**
 2. Every ```*.hpp``` file should have ```#define``` guard like this ```__nobodyxu_concept_check_($DIR_TO_THE_FILE)_($FILE_NAME)_HPP__```(Note: There should be no ```/``` but ```_``` in the guard).
 3. When including files, include ```STL``` first, then files from subdir, files from the current dir and finally the files from the parent dir. The includes should be in alphabetical order. A file can be omitted if other included files include that file. **However, if the file defines macros that help writing concepts(Ex ```/include/concepts/def_convenient_macros.hpp```), it should be the last to be included and at the end of the file before the end of the ```#endif``` guard, a ```undef_convenient_macros.hpp``` should be included.**
 4. Try to include as less as you can and use C++ language feature if possible.
 5. If you have to invent a new wheel, put it under ```/include/```.
 6. All concepts should be put under namespace ```nxwheels```. The ```using``` alias used to check the concept and the nothrow concepts impl checking whether ```noexcept(ACTIONS)``` is true should be put under namespace ```nxwheels``` for extendability(other might use ```using``` alias to check the returned type of an operation and use the nothrow concepts impl because they have checked the expression elsewhere).
 7. Concepts defined in ```/include/concepts/operations``` should be able to handle reference while concepts defined in other places don't.
 8. If you can extract the pattern of the concepts defined to make it more readable(Ex in ```/include/concepts/operations/is_arithmetic_v.hpp```), then you should extract it even at the cost of using ```macro``` as long as you ```#undef``` it at the end of the file before the ```#endif``` guard.

 ### Release
 This repository use [Semantic Versioning 2.0.0](https://semver.org/).
