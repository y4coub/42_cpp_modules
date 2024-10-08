/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:30:51 by yaharkat          #+#    #+#             */
/*   Updated: 2024/10/08 13:30:51 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria *materias[4];

public:
	Character();
	Character(Character const &other);
	Character &operator=(Character const &rhs);
	~Character();

	Character(std::string const &name);

	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

	std::string const &getName() const;
};