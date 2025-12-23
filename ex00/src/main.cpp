/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:50:53 by francesca         #+#    #+#             */
/*   Updated: 2025/12/23 12:23:49 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap one("Pippo");
    
    one.attack("Immaginary Target");
    one.setAttackDamage(1);
    one.attack("Immaginary Target");
    one.takeDamage(2);
    one.beRepaired(2);
    one.takeDamage(15);
    one.attack("Immaginary Target");
    one.beRepaired(2);
    return(0);
}
