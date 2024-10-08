/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:30:33 by yaharkat          #+#    #+#             */
/*   Updated: 2024/10/08 13:30:33 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	// Amateria is abstract not needed in this case this->type = rhs.type is impossible because type is const;
	(void)rhs;
	return *this;
}

AMateria::~AMateria()
{
}

void AMateria::use(ICharacter &target)
{
	std::cout << "You have no Materia to use on " << target.getName() << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
}

std::string const &AMateria::getType(void) const
{
	return type;
}