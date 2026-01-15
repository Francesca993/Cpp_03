/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:50:53 by francesca         #+#    #+#             */
/*   Updated: 2026/01/15 14:55:31 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// int main(void)
// {
//     ClapTrap one("Pippo");
//     one.attack("CLAP TARGET");
//     one.takeDamage(4);
//     one.beRepaired(2);
//     one.takeDamage(15);
//     one.attack("CLAP Target");
//     one.beRepaired(2);
    
//     ScavTrap first("Paperino");
//     first.attack("SCAV TARGET");
//     first.takeDamage(6);
//     first.beRepaired(10);
//     first.guardGate();
//     first.attack("SCAV TARGET");
    
//     return(0);
// }


static void separator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    separator("1) BASIC CLAPTRAP");
    ClapTrap c("Pippo");
    c.attack("Target");
    c.takeDamage(3);
    c.beRepaired(2);

    separator("2) BASIC SCAVTRAP + GUARDGATE");
    ScavTrap s("Paperino");
    s.attack("Target");      // deve stampare "ScavTrap ..."
    s.guardGate();           // entra in gate keeper mode
    s.guardGate();           // già ON

    separator("3) ENERGY DRAIN (SCAVTRAP attacks)");
    // ScavTrap parte con 50 energy: facciamo 51 attacchi per vedere il blocco
    for (int i = 0; i < 51; i++)
        s.attack("Dummy");

    separator("4) DEAD STATE (HP = 0)");
    s.takeDamage(1000);      // clamp a 0
    s.attack("Dummy");       // deve fallire (no hit points)
    s.beRepaired(5);         // deve fallire (no hit points)
    s.guardGate();           // (se vuoi) può stampare comunque; non è vincolato dal subject

    separator("5) COPY CONSTRUCTOR (ScavTrap)");
    ScavTrap a("Alpha");
    a.guardGate();
    a.takeDamage(10);
    ScavTrap b(a);           // copy constructor
    b.attack("CopyTarget");
    b.guardGate();

    separator("6) COPY ASSIGNMENT (ScavTrap)");
    ScavTrap d("Delta");
    //d = a;                   // operator=
    d.attack("AssignTarget");
    d.guardGate();

    separator("7) POLYMORPHISM TEST (base pointer)");
    // utile solo se ClapTrap::attack è virtual (come nel tuo header)
    ClapTrap* base = new ScavTrap("Poly");
    base->attack("BaseTarget");  // se virtual -> stampa "ScavTrap ..."
    delete base;                 // se ClapTrap destructor è virtual -> chiama anche ~ScavTrap

    separator("END");
    return 0;
}
