/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:50:53 by francesca         #+#    #+#             */
/*   Updated: 2025/12/23 12:38:00 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap one("Pippo");
    
    one.attack("Immaginary Target");
    one.attack("Immaginary Target");
    one.takeDamage(4);
    one.beRepaired(2);
    one.takeDamage(15);
    one.attack("Immaginary Target");
    one.beRepaired(2);
    return(0);
}
