/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:05:45 by francesca         #+#    #+#             */
/*   Updated: 2026/01/15 12:21:51 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("DefaultClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << GREEN << "ClapTrap Constructor Default called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << GREEN << "ClapTrap Constructor Parametric Default called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other){
    std::cout << YELLOW << "ClapTrap Copy constructor called" << RESET << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other){
    std::cout << BLUE << "ClapTrap Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

int ClapTrap::getEnergyPoints() const{
    return(this->_energyPoints);
}

int ClapTrap::getHitPoints()const{
    return(this->_hitPoints);
}

int ClapTrap::getDamageValue()const{
    return(this->_attackDamage);
}

std::string ClapTrap::getName()const{
    return(this->_name);
}

ClapTrap::~ClapTrap(){
    std::cout << MAGENTA << "ClapTrap Destructor operator called" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0) {
        std::cout << RED << "ClapTrap " << _name
                  << " is already destroyed. Can't take more damage."
                  << RESET << std::endl;
        return;
    }

    // clamp: se il danno è >= HP, vai direttamente a 0
    if (amount >= static_cast<unsigned int>(_hitPoints)) {
        _hitPoints = 0;
        std::cout << ORANGE << "ClapTrap " << amount << " points of life." << RESET << std::endl;
        std::cout << RED << "ClapTrap Hit Points are 0. You lose. Can you retry =) " << RESET << std::endl;
        return;
    }

    _hitPoints -= static_cast<int>(amount);

    std::cout << ORANGE << "ClapTrap  " << amount << " points of life." << RESET << std::endl;
    std::cout << RED << "ClapTrap Hit Points are " << _hitPoints << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (_hitPoints <= 0)
    {
        std::cout << RED << "ClapTrap " << _name << " can't attack (no hit points left)."
                  << RESET << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << RED << "ClapTrap " << _name
                  << " can't attack (no energy points left)."
                  << RESET << std::endl;
        return;
    }
    this->_energyPoints -=1;
    std::cout << YELLOW << "ClapTrap " << _name << " attacks " << target << ".";
    std::cout << " Causing "  << _attackDamage << " points of damage!" 
              << " (EP now: " << _energyPoints << ")" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (_hitPoints <= 0) 
    {
        std::cout << RED << "ClapTrap " << _name
                  << " can't be repaired (no hit points left)."
                  << RESET << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
    std::cout << RED << "ClapTrap " << _name
              << " can't be repaired (no energy points left)."
              << RESET << std::endl;
        return;
    }
    this->_energyPoints -=1;
    this->_hitPoints += static_cast<int>(amount);
    std::cout << BLUE << "ClapTrap be repaired for " << amount << " points of life"
              << " (HP now: " << _hitPoints
              << ", EP now: " << _energyPoints << ")"
              << RESET << std::endl;
}
