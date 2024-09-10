/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:18:47 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/06 17:23:49 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP_
#define HARL_HPP_

#include <iostream>

enum Level {
  DEBUG,
  INFO,
  WARNING,
  ERROR
};

class Harl {
 public:
  Harl();
  ~Harl();
  void complain(int level);

 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
};

#endif // 
