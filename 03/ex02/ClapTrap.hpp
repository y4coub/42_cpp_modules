/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:26:09 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/10 14:18:10 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &rhs);
	~ClapTrap();
	void attack(const std::string &target);
	void attack(ClapTrap &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void costEnergy(unsigned int amount);
	std::string getName() const;
	void setName(std::string name);
	void setHitPoints(int hitPoints);
	void setEnergyPoints(int energyPoints);
	void setAttackDamage(int attackDamage);

private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
};

#endif
