/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:05:45 by francesca         #+#    #+#             */
/*   Updated: 2025/12/23 12:20:10 by francesca        ###   ########.fr       */
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
    std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other){
    std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

void ClapTrap::setAttackDamage(int dmg){
    std::cout << GREEN << "You've setted the damege at "<< dmg << RESET << std::endl;
    this->_attackDamage = dmg;
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
    std::cout << MAGENTA << "Destructor operator called" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (_hitPoints <= 0) 
    {
        std::cout << RED << "ClapTrap " << _name
                  << " is already destroyed. Can't take more damage." 
                  << RESET << std::endl;
        return;
    }
    int dmg = static_cast<int>(amount);
    this->_hitPoints -= dmg;
    std::cout << ORANGE << "You loosing " << amount << " points of life." << RESET << std::endl;
    if (_hitPoints <= 0)
    {
        this->_hitPoints = 0;
        std::cout << RED << "Your Hit Points are 0. You loose. Can You retry =) "<< RESET << std::endl;
    }
    else
        std::cout << RED << "Your Hit Points are " << _hitPoints << RESET << std::endl;
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
    std::cout << BLUE << "ClapTrap be repaired for " << amount << " points of life"
              << " (HP now: " << _hitPoints
              << ", EP now: " << _energyPoints << ")"
              << RESET << std::endl;
    this->_hitPoints += static_cast<int>(amount);;
}