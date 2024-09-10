/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:39:57 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/01 15:43:21 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie z = Zombie(name);
	z.announce();
}