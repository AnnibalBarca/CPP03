#include "ClapTrap.hpp"

int main()
{
    ClapTrap vince;
    ClapTrap mateo("Mateo");
    ClapTrap corentin(mateo);

    corentin = vince;

    // vince.attack("an enemy");
    // mateo.takeDamage(3);
    // mateo.beRepaired(2);
    // mateo.takeDamage(100);
    // mateo.attack("ghost");
    // mateo.beRepaired(5);

    return 0;
}