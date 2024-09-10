/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:08:49 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/10 14:39:49 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &rhs);
	~ScavTrap();
	void guardGate();
	void setGateKeeperMode(void);
	void attack(const std::string &target);
private:
	bool _gateKeeperMode;
};

#endif
