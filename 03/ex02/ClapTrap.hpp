/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:15:54 by yaharkat          #+#    #+#             */
/*   Updated: 2024/10/01 16:51:50 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <iostream>
class ClapTrap
{
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &rhs);
	~ClapTrap();
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	unsigned int getHitpoints();
	unsigned int getEnergyPoints();
	unsigned int getAttackDamage();
	std::string getName();
	void setHitpoints(unsigned int hitpoints);
	void setEnergyPoints(unsigned int energy_points);
	void setAttackDamage(unsigned int attack_damage);

protected:
	std::string _name;
	int _hitpoints;
	int _energy_points;
	int _attack_damage;
};

#endif
