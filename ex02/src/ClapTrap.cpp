/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:05:45 by francesca         #+#    #+#             */
/*   Updated: 2026/01/04 18:43:53 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("DefaultClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << GREEN << "Constructor Default called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << GREEN << "Constructor Parametric Default called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other){
    std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other){
    std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
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

std::string ClapTrap::getName(){
    return(this->_name);
}

ClapTrap::~ClapTrap(){
    std::cout << GREEN << "Destructor operator called" << RESET << std::endl;
}

std::string ClapTrap::getTypName()
{ 
    return ("ClapTrap"); 
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->getHitPoints() <= 0) {
        std::cout << GREEN << this->getTypName() << " " << _name
                  << " is already destroyed. Can't take more damage."
                  << RESET << std::endl;
        return;
    }

    // clamp: se il danno è >= HP, vai direttamente a 0
    if (amount >= static_cast<unsigned int>(_hitPoints)) {
        _hitPoints = 0;
        std::cout << GREEN << this->getTypName() << " lose " << amount << " points of life." << RESET << std::endl;
        std::cout << GREEN << "Your Hit Points are 0. You lose. Can you retry =) " << RESET << std::endl;
        return;
    }

    _hitPoints -= static_cast<int>(amount);

    std::cout << GREEN << this->getTypName() << " lose " << amount << " points of life." << RESET << std::endl;
    std::cout << GREEN << "Your Hit Points are " << _hitPoints << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (this->getHitPoints() <= 0)
    {
        std::cout << GREEN << this->getTypName() << " " << _name << " can't attack (no hit points left)."
                  << RESET << std::endl;
        return;
    }
    if (this->getEnergyPoints() <= 0) {
        std::cout << GREEN << this->getTypName() << " " << _name
                  << " can't attack (no energy points left)."
                  << RESET << std::endl;
        return;
    }
    this->_energyPoints -=1;
    std::cout << GREEN << this->getTypName() << " " << _name << " attacks " << target << ".";
    std::cout << " Causing "  << _attackDamage << " points of damage!" 
              << " (EP now: " << _energyPoints << ")" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->getHitPoints() <= 0) 
    {
        std::cout << GREEN << this->getTypName() << " " <<  _name
                  << " can't be repaired (no hit points left)."
                  << RESET << std::endl;
        return;
    }
    if (this->getEnergyPoints() <= 0) {
    std::cout << GREEN << this->getTypName() << " " << _name
              << " can't be repaired (no energy points left)."
              << RESET << std::endl;
        return;
    }
    this->_energyPoints -=1;
    std::cout << GREEN <<  this->getTypName() << " " << _name << " be repaired for " << amount << " points of life"
              << " (HP now: " << _hitPoints
              << ", EP now: " << _energyPoints << ")"
              << RESET << std::endl;
    this->_hitPoints += static_cast<int>(amount);;
}
