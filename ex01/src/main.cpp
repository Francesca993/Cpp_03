/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:50:53 by francesca         #+#    #+#             */
/*   Updated: 2026/01/04 17:02:47 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap one("Pippo");
    ScavTrap first("Paperino");
    
    one.attack("Immaginary Target");
    one.attack("Immaginary Target");
    first.attack("Pippo");
    one.takeDamage(4);
    first.takeDamage(6);
    one.beRepaired(2);
    first.beRepaired(10);
    first.guardGate();
    one.takeDamage(15);
    one.attack("Immaginary Target");
    first.attack("Pippo");
    one.beRepaired(2);
    return(0);
}
