/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:30:53 by yaharkat          #+#    #+#             */
/*   Updated: 2024/10/08 13:30:53 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const &other) : AMateria(other)
{
}

Cure::~Cure()
{
}

Cure &Cure::operator=(Cure const &rhs)
{
	// Not needed
	(void)rhs;
	return *this;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << YELLOW;
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	std::cout << RESET;
}