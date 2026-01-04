/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:41:21 by francesca         #+#    #+#             */
/*   Updated: 2026/01/04 18:36:57 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

//–––––––––––––––––––––––––––––
// Colors Background for Output
// –––––––––––––––––––––––––––––
# define BG_BLUE     "\033[44m"

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public:
    ScavTrap(); // Default
    ScavTrap(std::string name); // Parametric
    ScavTrap(const ScavTrap& other); // Copy ctor
    ScavTrap& operator=(const ScavTrap& other); // copy assign
    ~ScavTrap();
    bool _guardGate;
    
    bool getGuard();
    void attack(const std::string& target);
    void guardGate();
    std::string getTypName();

};

#endif