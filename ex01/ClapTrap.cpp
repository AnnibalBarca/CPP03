#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    if (&src != this)
    {
        _name = src._name;
        _hitPoints = src._hitPoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }
    std::cout << "Copy constructor of " << src._name << " called !" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
    std::cout << "Claptrap operator overload!" << std::endl;
    return *this;
}

ClapTrap::ClapTrap()
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been constructed\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " has been destroyed\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no hit points and cannot attack\n";
        return;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points and cannot attack\n";
        return;
    }
    --_energyPoints;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already at 0 hit points\n";
        return;
    }
    int damage = static_cast<int>(amount);
    _hitPoints -= damage;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << damage << " points of damage, " << _hitPoints << " HP left\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no hit points and cannot be repaired\n";
        return;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points and cannot repair\n";
        return;
    }
    --_energyPoints;
    _hitPoints += static_cast<int>(amount);
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " points, " << _hitPoints << " HP now\n";
}