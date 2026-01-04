/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:41:21 by francesca         #+#    #+#             */
/*   Updated: 2026/01/04 16:34:20 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

//–––––––––––––––––––––––––––––
// Colors for Output
// –––––––––––––––––––––––––––––
# define CYAN        "\033[36m"
# define BRIGHT_CYAN "\033[96m"
# define WHITE       "\033[97m"
# define GREY        "\033[90m"
# define BOLD        "\033[1m"
# define UNDERLINE   "\033[4m"

// Background varianti utili per banner
# define BG_BLUE     "\033[44m"
# define BG_CYAN     "\033[46m"
# define BG_YELLOW   "\033[43m"

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

};

#endif