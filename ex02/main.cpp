#include "FragTrap.hpp"

int main(){
    FragTrap s("Fragenger");
    s.attack("Enemy");
    for(int i=0;i<51;++i) s.attack("Target");
    s.beRepaired(10);
    s.takeDamage(120);
    s.highFivesGuys();
    FragTrap t(s);
    FragTrap u;
    u = s;
    FragTrap* p = new FragTrap("Heap");
    delete p;
    return 0;
}