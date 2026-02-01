#include "Zombie.hpp"

int main(void)
{
    int     N = 42;
    Zombie* zombies = zombieHorde(N, "Foo");
    if (!zombies)
        return (1);
    for (int i = 0; i < N; i++) {
        zombies[i].announce();
    }
    delete[] zombies;
    return (0);
}