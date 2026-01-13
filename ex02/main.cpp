#include "ScavTrap.hpp"

int main() {
    ScavTrap a("Alice");
    // ClapTrap b("Bob");

    a.attack("EvilBot");

    // b.takeDamage(3);

    // b.beRepaired(2);

    for (int i = 0; i < 12; ++i)
        a.attack("Target");

    a.beRepaired(1);
    a.takeDamage(100);
    a.guardGate();
    // b.attack("Ghost");       // should not be allowed when HP == 0
    // b.beRepaired(5);         // still not allowed if rule forbids actions when HP == 0

    return 0;
}