/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:41:40 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/01 16:03:30 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	const int ITTER_N = 5;
	Zombie *zombie = zombieHorde(ITTER_N, "hamid");

	for (int i = 0; i < ITTER_N; i++)
		zombie[i].announce();

	delete[] zombie;
}