/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:00:26 by francesca         #+#    #+#             */
/*   Updated: 2026/01/15 14:44:58 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other), _guardGate(other._guardGate) {
    std::cout << BG_BLUE << "ScavTrap Copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
    std::cout << BG_BLUE << "ScavTrap Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_guardGate = other._guardGate;
    }
    return (*this);
}

ScavTrap::~ScavTrap(){
    std::cout << BG_BLUE << "ScavTrap Destructor operator called" << RESET << std::endl;
}

bool ScavTrap::getGuard() const{
    return(this->_guardGate);
}

void ScavTrap::attack(const std::string& target) {
    if (this->getHitPoints() <= 0)
    {
        std::cout << BG_BLUE << "ScavTrap " <<  this->getName()<< " can't attack (no hit points left)."
                  << RESET << std::endl;
        return;
    }
    if (this->getEnergyPoints() <= 0) {
        std::cout << BG_BLUE << "ScavTrap " << this->getName()
                  << " can't attack (no energy points left)."
                  << RESET << std::endl;
        return;
    }
    this->_energyPoints -=1;
    std::cout << BG_BLUE << "ScavTrap " << this->getName() << " attacks " << target << ".";
    std::cout << " Causing "  << _attackDamage << " points of damage!" 
              << " (EP now: " << _energyPoints << ")" << RESET << std::endl;
}

void ScavTrap::guardGate(){
    if (this->getGuard() == 0)
    {
        std::cout << BG_BLUE << "ScavTrap Guardgate enter in modality Gate keeper mode" << RESET << std::endl;
        this->_guardGate = true;
    }
    else
        std::cout << BG_BLUE << "Modality of ScavTrap Guardgate is: ON" << RESET << std::endl;
}
