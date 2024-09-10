/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:49:03 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/01 15:56:39 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombieHord = new Zombie[N];
	for (int i = 0; i < N; i++)
		new (&zombieHord[i]) Zombie(name);
	return zombieHord;
}