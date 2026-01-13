#include "ScavTrap.hpp"

int main(){
    ScavTrap s("Scavenger");
    s.attack("Enemy");
    for(int i=0;i<51;++i) s.attack("Target");
    s.beRepaired(10);
    s.takeDamage(120);
    s.guardGate();
    ScavTrap t(s);
    ScavTrap u;
    u = s;
    ScavTrap* p = new ScavTrap("Heap");
    delete p;
    return 0;
}