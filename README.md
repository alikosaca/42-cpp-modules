# 42 C++ Modules (CPP00 – CPP09)

My solutions to the ten C++ modules of the 42 curriculum — a step-by-step path from C to object-oriented C++, covering classes, inheritance, polymorphism, exceptions, casts, templates and the STL.

All code is written in **C++98** and compiled with `-Wall -Wextra -Werror -std=c++98`.

## Modules

| Module | Topics | Exercises |
|---|---|---|
| [**CPP00**](cpp00) | Namespaces, classes, member functions, `iostream`, static / const | `Megaphone`, `PhoneBook` (contact manager) |
| [**CPP01**](cpp01) | Memory allocation, references vs pointers, pointers to members, `switch` | `Zombie`, zombie horde, `HumanA` / `HumanB` / `Weapon`, `Sed` (file replace), `Harl` complaint filter |
| [**CPP02**](cpp02) | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form | `Fixed` point number class with arithmetic and comparison operators |
| [**CPP03**](cpp03) | Inheritance | `ClapTrap` → `ScavTrap`, `FragTrap` |
| [**CPP04**](cpp04) | Subtype polymorphism, abstract classes, deep copy | `Animal` / `Dog` / `Cat` with `Brain`, `WrongAnimal`, abstract `AAnimal` |
| [**CPP05**](cpp05) | Exceptions, try / catch | `Bureaucrat`, `Form` / `AForm`, Shrubbery / Robotomy / Presidential forms, `Intern` |
| [**CPP06**](cpp06) | C++ casts (`static_cast`, `reinterpret_cast`, `dynamic_cast`) | `ScalarConverter`, `Serializer`, runtime type identification with `Base` / `A` / `B` / `C` |
| [**CPP07**](cpp07) | Function and class templates | `swap` / `min` / `max`, `iter`, `Array<T>` |
| [**CPP08**](cpp08) | Templated containers, iterators, algorithms | `easyfind`, `Span`, `MutantStack` (iterable `std::stack`) |
| [**CPP09**](cpp09) | STL containers in practice | `BitcoinExchange` (`std::map`), `RPN` calculator (`std::stack`), `PmergeMe` Ford–Johnson sort (`std::vector` + `std::deque`) |

## Build & run

Each exercise is self-contained with its own `Makefile`:

```bash
cd cpp09/ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

Some highlights:

```bash
# CPP09 ex00 – Bitcoin value on a given date
cd cpp09/ex00 && make && ./btc input.txt

# CPP09 ex02 – merge-insertion sort, timed on two containers
cd cpp09/ex02 && make && ./PmergeMe 3 5 9 7 4

# CPP06 ex00 – convert a literal to char, int, float and double
cd cpp06/ex00 && make && ./myconvert 42.0f
```

## What I learned

- Thinking in objects: encapsulation, constructors / destructors, the Orthodox Canonical Form
- Inheritance, virtual functions, abstract classes and avoiding shallow copies
- Error handling with exceptions
- Generic programming with templates
- Choosing the right STL container and algorithm for the job

## License

MIT
