/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:43:44 by yaharkat          #+#    #+#             */
/*   Updated: 2024/10/04 17:02:48 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <iostream>

class Brain
{
public:
	Brain(std::string idea);
	Brain(const Brain &other);
	Brain &operator=(const Brain &rhs);
	~Brain();
	std::string getIdea(int i) const;
private:
	std::string ideas[100];
};

#endif
