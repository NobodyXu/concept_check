# concept_check
This is a C++14 header-only concept check library.

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
I created this library due to my hate for the ugly and disturbed syntex of ```The Boost Concept Check library```. It forces you to use ```BOOST_CONCEPT_REQUIRES``` which requires you to put your return type into it, or use ```BOOST_CONCEPT_ASSERT```. What's more, the way to extend it is quite strange to me -- you create another class in lines to check it.

This library is intended to be clear in syntex and reusable and let users have freedom on how concepts are checked in their program.

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

## How this works
Most of the concepts defined in this library use ```declval``` defined in ```/include/utility.hpp``` to "get" instance of a type in an unevaluated context and class template ```is_detected_v``` in ```/include/detector_core.hpp``` to check whether an expression is valid. ```is_detected_v``` is a library fundamentals TS v2 feature, you can find more description of it at [here](https://en.cppreference.com/w/cpp/experimental/is_detected). My detector is compliant to its API.

## Reason why some of the utility and concepts are rewriten here despite ```STL``` has defined them
 1. The code from ```libstdc++``` keep emitting nonsense errors(std::declval keep giving out errors due to a fail in static_assert that checks for use in evaluated context);
 2. They haven't got the feature I want(std::add_reference in ```libstdc++``` won't work correctly for ```int () &``` because that is a ```C++17``` feature);
 3. I don't want to have too much dependency on ```type_traits```(usefull_types.hpp, bool_constant.hpp and type_tuple.hpp) and I am still thinking of whether I should delete them and depent on ```STL``` or be more independent of it.
 4. My version of them have more features. Ex the ```/include/concepts/operations/is_constructible_v.hpp``` can not only check whether a type ```T``` can be [direct initialized](https://en.cppreference.com/w/cpp/language/direct_initialization) from ```Args...```, it can also check whether it is [list-initializable](https://en.cppreference.com/w/cpp/language/list_initialization) or initializer_list-initializable.

## Contribution
I welcome anyone to contribute to this repository, and you can find me on Github or by email(displayed in my personal details on Github). If you have an issue, post it on Github Issues and I will repond to you as soon as possible.
