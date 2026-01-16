/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap_02.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:41:21 by francesca         #+#    #+#             */
/*   Updated: 2026/01/16 06:59:35 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_02_HPP
#define SCAVTRAP_02_HPP

//–––––––––––––––––––––––––––––
// Colors Background for Output
// –––––––––––––––––––––––––––––
# define BG_BLUE     "\033[44m"

#include "ClapTrap_02.hpp"

class ScavTrap : public ClapTrap{
    private:
    bool _guardGate;
    
    public:
    ScavTrap(); // Default
    ScavTrap(std::string name); // Parametric
    ScavTrap(const ScavTrap& other); // Copy ctor
    ScavTrap& operator=(const ScavTrap& other); // copy assign
    ~ScavTrap();
    
    //Methods
    bool getGuard() const;
    void attack(const std::string& target);
    void guardGate();
    std::string getType() const;

};

#endif