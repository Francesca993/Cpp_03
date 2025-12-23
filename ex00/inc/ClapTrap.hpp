/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:43:38 by francesca         #+#    #+#             */
/*   Updated: 2025/12/23 12:19:13 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

//–––––––––––––––––––––––––––––
// Colors for Output
// –––––––––––––––––––––––––––––
# define GREEN "\033[32m"
# define ORANGE "\033[38;5;214m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"

#include <iostream>
#include <string>

class ClapTrap{
    private:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;
    
    public:
    ClapTrap(); // Default
    ClapTrap(std::string name); // Parametric
    ClapTrap(const ClapTrap& other); // Copy ctor
    ClapTrap& operator=(const ClapTrap& other); // copy assign
    ~ClapTrap(); 
    
    // Getters
    void setAttackDamage(int dmg);
    int getEnergyPoints() const;
    int getHitPoints() const;
    int getDamageValue() const;
    std::string getName();

    // Methods
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
};

#endif

