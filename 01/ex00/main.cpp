/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:41:40 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/01 15:47:25 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	// heap allocation
	Zombie *zombie = newZombie("hamid");
	zombie->announce();
	delete zombie;
	// stack allocation
	randomChump("yahya");
}