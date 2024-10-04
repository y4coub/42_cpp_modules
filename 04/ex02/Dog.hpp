/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 01:11:53 by yaharkat          #+#    #+#             */
/*   Updated: 2024/10/04 16:55:09 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP_
#define DOG_HPP_
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog(std::string idea);
	Dog(const Dog &other);
	Dog &operator=(const Dog &rhs);
	~Dog();
	void makeSound(void) const;
	Brain &getBrain();

private:
	Brain *brain;
};

#endif
