#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " has been constructed\n";
}
FragTrap::FragTrap()
{}

FragTrap::FragTrap(const FragTrap &src)
    : ClapTrap(src)
{
    std::cout << "FragTrap copy constructor of " << src._name << " called !" << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " has been destroyed\n";
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    if (this != &src)
        ClapTrap::operator=(src);
    std::cout << "FragTrap operator overload!" << std::endl;
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " has no hit points and cannot attack\n";
        return;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " has no energy points and cannot attack\n";
        return;
    }
    --_energyPoints;
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " is already at 0 hit points\n";
        return;
    }
    int damage = static_cast<int>(amount);
    _hitPoints -= damage;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "FragTrap " << _name << " takes " << damage << " points of damage, " << _hitPoints << " HP left\n";
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " has no hit points and cannot be repaired\n";
        return;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " has no energy points and cannot repair\n";
        return;
    }
    --_energyPoints;
    _hitPoints += static_cast<int>(amount);
    std::cout << "FragTrap " << _name << " repairs itself for " << amount << " points, " << _hitPoints << " HP now\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Fragtrap " << _name << " requests for a high five !" << std::endl;
}
