#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap(const std::string& name);
    FragTrap();
    ~FragTrap();
    FragTrap(const FragTrap &src);
    FragTrap &operator=(const FragTrap &cpy);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void highFivesGuys(void);
};

#endif