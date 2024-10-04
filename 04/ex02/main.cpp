#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	// Animal* animal = new Animal();

	Animal *dog = new Dog("I'm a Dog");
	Animal *cat = new Cat("I'm a Cat");

	dog->makeSound();
	cat->makeSound();

	Animal *animals[2];
	animals[0] = new Dog("I'm a Dog");
	animals[1] = new Cat("I'm a Cat");

	for (int i = 0; i < 2; i++)
		animals[i]->makeSound();

	delete dog;
	delete cat;
	delete animals[0];
	delete animals[1];

	return 0;
}
