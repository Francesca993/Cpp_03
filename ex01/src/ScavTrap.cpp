/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:00:26 by francesca         #+#    #+#             */
/*   Updated: 2026/01/04 17:06:28 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
class ScavTrap : public ClapTrap{
    public:
    ScavTrap(); // Default
    ScavTrap(std::string name); // Parametric
    ScavTrap(const ScavTrap& other); // Copy ctor
    ScavTrap& operator=(const ScavTrap& other); // copy assign
    ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
    bool guardGate;

};
*/

ScavTrap::ScavTrap(): ClapTrap("DefaultScavTrap") {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _guardGate = false;

    std::cout << BG_BLUE << "ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _guardGate = false;

    std::cout << BG_BLUE << "ScavTrap parametric constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other){
    std::cout << BG_BLUE << "ScavTrap Copy constructor called" << RESET << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_guardGate = other._guardGate;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
    std::cout << BG_BLUE << "ScavTrap Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
        this->_guardGate = other._guardGate;
    }
    return (*this);
}

ScavTrap::~ScavTrap(){
    std::cout << BG_BLUE << "ScavTrap Destructor operator called" << RESET << std::endl;
}

bool ScavTrap::getGuard(){
    return(this->_guardGate);
}

void ScavTrap::attack(const std::string& target){
    if (this->getHitPoints() <= 0)
    {
        std::cout << BG_BLUE << "ScavTrap " << _name << " can't attack (no hit points left)."
                  << RESET << std::endl;
        return;
    }
    if (this->getEnergyPoints() <= 0) {
        std::cout << BG_BLUE << "ScavTrap " << _name
                  << " can't attack (no energy points left)."
                  << RESET << std::endl;
        return;
    }
    this->_energyPoints -=1;
    std::cout << BG_BLUE << "ScavTrap " << _name << " attacks " << target << ".";
    std::cout << " Causing "  << _attackDamage << " points of damage!" 
              << " (EP now: " << _energyPoints << ")" << RESET << std::endl;
}

void ScavTrap::guardGate(){
    if (this->getGuard() == 0)
        std::cout << BG_BLUE << "Modality of ScavTrap Guardgate is: OFF" << RESET << std::endl;
    else
        std::cout << BG_BLUE << "Modality of ScavTrap Guardgate is: ON" << RESET << std::endl;
}
