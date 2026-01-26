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

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is in gate keeper mode" << std::endl;
}

