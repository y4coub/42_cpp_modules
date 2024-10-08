/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:30:44 by yaharkat          #+#    #+#             */
/*   Updated: 2024/10/08 13:30:44 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

#define RED "\033[31m"
#define AQUA "\033[36m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class AMateria
{
protected:
	const std::string type;

public:
	AMateria();
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &rhs);
	virtual ~AMateria();

	AMateria(std::string const &type);

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

	std::string const &getType() const;
};
