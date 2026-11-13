# C++ Modules (CPP00 – CPP09)

All ten C++ modules of the 42 curriculum: an introduction to C++, from classes up to the STL. Everything is written in C++98 and compiled with `-Wall -Wextra -Werror`.

| Module | Topic | Exercises |
| --- | --- | --- |
| CPP00 | Classes, member functions, iostreams | Megaphone, PhoneBook, Account |
| CPP01 | Memory allocation, references, pointers to member functions | Zombie horde, Weapon/Human, file replace, Harl |
| CPP02 | Operator overloading, Orthodox Canonical Form | Fixed-point number class, point in triangle (BSP) |
| CPP03 | Inheritance | ClapTrap, ScavTrap, FragTrap |
| CPP04 | Polymorphism, abstract classes, deep copies | Animal, Cat, Dog, Brain |
| CPP05 | Exceptions | Bureaucrat, forms, Intern |
| CPP06 | C++ casts | ScalarConverter, Serializer, type identification |
| CPP07 | Templates | swap/min/max, iter, Array class template |
| CPP08 | Templated containers, iterators, algorithms | easyfind, Span, MutantStack |
| CPP09 | STL containers | BitcoinExchange, RPN calculator, PmergeMe |

## Highlights

### Fixed-point numbers and BSP (CPP02)

A `Fixed` class stores numbers as an integer with 8 fractional bits. It overloads the comparison, arithmetic and increment operators, so it can be used like a built-in number type. The last exercise uses it to check whether a point lies inside a triangle (binary space partitioning).

### ScalarConverter (CPP06/ex00)

Takes a C++ literal as a string, detects whether it is a `char`, `int`, `float` or `double`, and converts it to the other three types with explicit casts. It handles the special values `nan`, `+inf` and `-inf`, and reports conversions that are impossible or not displayable.

```sh
./convert 42.0f
```

### MutantStack (CPP08/ex02)

`std::stack` has no iterators. `MutantStack` inherits from it and exposes the iterators of the underlying container, so it can be looped over like a `std::list`.

### BitcoinExchange and RPN (CPP09/ex00, ex01)

- **BitcoinExchange** loads a CSV of historical Bitcoin prices into a `std::map` and evaluates an input file of `date | amount` lines. If a date is missing, it uses the closest earlier date. Invalid dates, negative or too large amounts get an error message.
- **RPN** evaluates expressions in Reverse Polish Notation with a `std::stack`:

```sh
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"   # 42
```

### PmergeMe (CPP09/ex02)

Sorts a list of positive integers with the **Ford-Johnson algorithm** (merge-insertion sort), which needs very few comparisons:

1. Pair up the numbers and sort each pair
2. Recursively sort the larger numbers of each pair
3. Insert the smaller numbers into that sorted chain with binary search, in an order based on the Jacobsthal numbers

The algorithm is a template, so it runs on both `std::vector` and `std::deque`, and the program prints the time each container needs.

```sh
cd CPP09/ex02
make
./PmergeMe 3 5 9 7 4
```

## Build an exercise

Every exercise has its own Makefile:

```sh
cd CPP04/ex01
make
./<program>
```
