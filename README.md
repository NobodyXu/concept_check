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

## Structure of the repository.
This library is header-only, so the structure of this repository quite simple.

 1. Stuffs that facilitate writing concepts, like ```detector_core.hpp``` and ```utility.hpp``` are put under ```/include``` directly.
 2. Concepts are all put under ```/include/concepts/```.
 3. Concepts that check a particular operation or member of a type are put under ```/include/concepts/operations/``` and ```/include/concepts/member``` respectively.
 4. Tests are put in another dir named ```/test/``` and has the similar structure as ```/include/```.

## Contribution
I welcome anyone to contribute to this repository, and you can find me on Github or by email(displayed in my personal details on Github). If you have an issue, post it on Github Issues and I will repond to you as soon as possible.
