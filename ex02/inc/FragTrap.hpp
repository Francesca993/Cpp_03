/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:46:50 by francesca         #+#    #+#             */
/*   Updated: 2026/01/16 06:59:22 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# define BRIGHT_CYAN "\033[96m"
# define WHITE       "\033[97m"
# define GREY        "\033[90m"
# define BOLD        "\033[1m"
# define UNDERLINE   "\033[4m"

#include "ClapTrap_02.hpp"

class FragTrap : public ClapTrap{
    public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void highFivesGuys(void);
    std::string getType() const;
};

#endif