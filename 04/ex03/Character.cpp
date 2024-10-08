/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:34:48 by yaharkat          #+#    #+#             */
/*   Updated: 2024/10/08 13:30:48 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	name = "You";
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

Character::Character(Character const &other)
{
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (other.materias[i])
			materias[i] = other.materias[i]->clone(); // Deep copy because clone use new
		else
			materias[i] = NULL;
	}
}

Character &Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
		for (int i = 0; i < 4; i++)
		{
			if (materias[i])
				delete materias[i];
			if (rhs.materias[i])
				materias[i] = rhs.materias[i]->clone(); // Deep copy because clone use new
			else
				materias[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (materias[i])
			delete materias[i];
}

Character::Character(std::string const &name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "You can't equip a NULL materia\n";
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!materias[i])
		{
			std::cout << "You equip the materia " << m->getType() << std::endl;
			materias[i] = m;
			return;
		}
	}
	std::cout << "You can't equip more than 4 materias\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Unequip : invalid index\n";
		return;
	}
	if (!materias[idx])
	{
		std::cout << "You can't unequip a materia that doesn't exist\n";
		return;
	}
	std::cout << "You unequip the materia " << materias[idx]->getType() << std::endl;
	delete materias[idx];
	materias[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Use : invalid index\n";
		return;
	}
	if (!materias[idx])
	{
		std::cout << "You can't use a materia that doesn't exist\n";
		return;
	}
	materias[idx]->use(target);
}

std::string const &Character::getName() const
{
	return name;
}