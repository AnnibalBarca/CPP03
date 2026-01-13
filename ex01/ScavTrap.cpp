#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " has been constructed\n";
}
ScavTrap::ScavTrap()
    : ClapTrap("DefaultScav")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " has been constructed\n";
}

ScavTrap::ScavTrap(const ScavTrap &src)
    : ClapTrap(src)
{
    std::cout << "ScavTrap copy constructor of " << src._name << " called !" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " has been destroyed\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    if (this != &src)
        ClapTrap::operator=(src);
    std::cout << "ScavTrap operator overload!" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " has no hit points and cannot attack\n";
        return;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " has no energy points and cannot attack\n";
        return;
    }
    --_energyPoints;
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " is already at 0 hit points\n";
        return;
    }
    int damage = static_cast<int>(amount);
    _hitPoints -= damage;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ScavTrap " << _name << " takes " << damage << " points of damage, " << _hitPoints << " HP left\n";
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " has no hit points and cannot be repaired\n";
        return;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " has no energy points and cannot repair\n";
        return;
    }
    --_energyPoints;
    _hitPoints += static_cast<int>(amount);
    std::cout << "ScavTrap " << _name << " repairs itself for " << amount << " points, " << _hitPoints << " HP now\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << "is in gate keeper mode" << std::endl;
}

