/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:46:11 by yaharkat          #+#    #+#             */
/*   Updated: 2024/10/04 23:55:22 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *j = new Dog("I'm a Dog 🐶");
	const Animal *i = new Cat("I'm a Cat 😺");
	delete j; // should not create a leak
	delete i;

	Animal *arr[4];
	arr[0] = new Dog("I'm a Dog 🐶");
	arr[1] = new Cat("I'm a Cat 😺");
	arr[2] = new Dog("I'm a Dog 🐕");
	arr[3] = new Cat("I'm a Cat 🐈");
	for (int i = 0; i < 4; i++)
	{
		arr[i]->makeSound();
		delete arr[i];
	}

	// testing deep copy
	Dog *dog = new Dog("I'm a Dog 🐶");
	Dog *dog2 = new Dog("I'm a Dog 🐕");

	*dog = *dog2;

	for (int i = 0; i < 100; i++)
	{
		std::cout << "Dog 1: " << dog->getBrain().getIdea(i) << std::endl;
		std::cout << "Dog 2: " << dog2->getBrain().getIdea(i) << std::endl;
	}
	delete dog;
	delete dog2;
}