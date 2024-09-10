/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:14:31 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/01 16:29:16 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("default")
{
}

Weapon::Weapon(std::string type) : _type(type)
{
}

void Weapon::setType(std::string type)
{
	_type = type;
}

const std::string &Weapon::getType() const
{
	return _type;
}

Weapon::~Weapon()
{
}