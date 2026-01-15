/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:53:23 by francesca         #+#    #+#             */
/*   Updated: 2026/01/15 15:27:12 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("DefaultFragTrap") {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << BLUE << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 10;
    _attackDamage = 30;

    std::cout << BLUE << "FragTrap default constructor called" << RESET << std::endl;
}

// FragTrap::FragTrap(const FragTrap& other){
//     std::cout << BLUE << "FragTrap copy constructor called" << RESET << std::endl;
//     this->_name = other._name;
//     this->_hitPoints = other._hitPoints;
//     this->_energyPoints = other._energyPoints;
//     this->_attackDamage = other._attackDamage;
// }

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << BLUE << "ScavTrap Copy constructor called" << RESET << std::endl;
}


FragTrap& FragTrap::operator=(const FragTrap&other){
    std::cout << BLUE << "FragTrap copy assign called" << RESET << std::endl;
    if (this != &other)
    {
        // this->_name = other._name;
        // this->_hitPoints = other._hitPoints;
        // this->_energyPoints = other._energyPoints;
        // this->_attackDamage = other._attackDamage;
        ClapTrap::operator=(other);
    }
    return (*this);
}

FragTrap::~FragTrap(){
    std::cout << BLUE << "FragTrap destructor called" << RESET << std::endl;
}

void FragTrap::highFivesGuys(void){
    std::cout << BLUE << "FragTrap "<< this->getName() << " requests a high five! ✋" << RESET << std::endl;
}

const std::string FragTrap::getType()
{ 
    return ("FragTrap"); 
}