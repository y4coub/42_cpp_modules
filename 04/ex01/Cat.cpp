/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:46:02 by yaharkat          #+#    #+#             */
/*   Updated: 2024/10/04 16:58:28 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(std::string idea) : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	brain = new Brain(idea);
	Animal::setType("Cat");
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	if (this != &other)
	{
		delete brain;
		brain = new Brain(*other.brain);
	}
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &rhs)
	{
		delete brain;
		brain = new Brain(*rhs.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow!!" << std::endl;
}

Brain &Cat::getBrain()
{
	return *brain;
}