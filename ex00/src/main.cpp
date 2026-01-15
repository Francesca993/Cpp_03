/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:50:53 by francesca         #+#    #+#             */
/*   Updated: 2026/01/15 12:24:10 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// int main(void)
// {
//     ClapTrap one("Pippo");
    
//     one.attack("Immaginary Target");
//     one.attack("Immaginary Target");
//     one.takeDamage(4);
//     one.beRepaired(2);
//     one.takeDamage(15);
//     one.attack("Immaginary Target");
//     one.beRepaired(2);
//     return(0);
// }

#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "\n===== BASIC FLOW =====\n";
    ClapTrap one("Pippo");

    one.attack("Immaginary Target");
    one.takeDamage(4);
    one.beRepaired(2);

    std::cout << "\n===== TEST: ENERGY DRAINS (attacks) =====\n";
    // ClapTrap parte con 10 energy: facciamo 11 attack per vedere il blocco
    for (int i = 0; i < 11; i++)
        one.attack("Dummy");

    std::cout << "\n===== TEST: ENERGY DRAINS (repairs) =====\n";
    // A questo punto dovrebbe avere energia 0: la repair deve fallire
    one.beRepaired(3);

    std::cout << "\n===== TEST: DAMAGE UNTIL DEAD =====\n";
    one.takeDamage(100);        // clamp a 0
    one.attack("Dummy");        // deve fallire per HP=0
    one.beRepaired(5);          // deve fallire per HP=0
    one.takeDamage(1);          // “already destroyed”

    std::cout << "\n===== TEST: COPY CONSTRUCTOR =====\n";
    ClapTrap a("Alpha");
    a.takeDamage(3);
    a.beRepaired(1);

    ClapTrap b(a); // copy constructor
    b.attack("CopyTarget");

    std::cout << "\n===== TEST: COPY ASSIGNMENT =====\n";
    ClapTrap c("Charlie");
    c = a; // operator=
    c.attack("AssignTarget");

    std::cout << "\n===== TEST: SELF ASSIGNMENT =====\n";
    c.attack("SelfAssignTarget");

    std::cout << "\n===== END =====\n";
    return 0;
}

