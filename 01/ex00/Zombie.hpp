/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 00:40:48 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/01 00:47:17 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{

private:
	std::string _name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif