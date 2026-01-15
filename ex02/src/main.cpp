/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:50:53 by francesca         #+#    #+#             */
/*   Updated: 2026/01/15 15:28:59 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap_02.hpp"
#include "ScavTrap_02.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap one("Archer");
    one.attack("CLAP TARGET");
    one.takeDamage(4);
    one.beRepaired(2);
    one.takeDamage(15);
    one.attack("CLAP Target");
    one.beRepaired(2);

    std::cout << "Finish Archer\n" << std::endl;
    
    ScavTrap first("Magician");
    first.attack("SCAV TARGET");
    first.takeDamage(6);
    first.beRepaired(10);
    first.guardGate();
    first.attack("SCAV TARGET");
    
    std::cout << "Finish Magician\n" << std::endl;
    
    ClapTrap* third = new ClapTrap("Tank");
    
    third->attack("CLAP2 TARGET");
    third->takeDamage(4);
    third->beRepaired(2);
    third->takeDamage(15);
    third->attack("CLAP2 Target");
    third->beRepaired(2);

    delete third;
    
    std::cout << "Finish Tank\n" << std::endl;
    
    FragTrap* second = new FragTrap("Healer");
    second->attack("TRAP TARGET");
    second->takeDamage(6);
    second->highFivesGuys();
    second->beRepaired(10);
    second->highFivesGuys();
    second->attack("TRAP TARGET");

    delete second;
    std::cout << "Finish Healer\n" << std::endl;
    
    return(0);
}