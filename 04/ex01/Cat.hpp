/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 01:10:55 by yaharkat          #+#    #+#             */
/*   Updated: 2024/10/04 16:55:13 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP_
#define CAT_HPP_
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat(std::string idea);
	Cat(const Cat &other);
	Cat &operator=(const Cat &rhs);
	~Cat();
	void makeSound(void) const;
	Brain &getBrain();

private:
	Brain *brain;
};

#endif
