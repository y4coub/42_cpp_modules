/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:46:11 by yaharkat          #+#    #+#             */
/*   Updated: 2024/10/01 01:29:20 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();	   // will output the cat sound!
	j->makeSound();	   // will output the dog sound!
	meta->makeSound(); // will output the generic animal sound!

	delete meta;
	delete j;
	delete i;

	std::cout << "---------------------" << std::endl;

	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *j2 = new WrongCat();

	std::cout << j2->getType() << " " << std::endl;
	std::cout << meta2->getType() << " " << std::endl;
	j2->makeSound();	// will output the cat sound!
	meta2->makeSound(); // will output the generic animal sound!
	j2->makeSound();	// will output the generic animal sound!

	return 0;
}