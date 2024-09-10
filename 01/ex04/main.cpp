/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:18:03 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/06 18:16:37 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <fstream>
#include <iostream>

bool err_args(int ac)
{
    if (ac < 3)
    {
        std::cout << "Usage: ./replace <filename> <string_to_replace> <replacement_string>" << std::endl;
        return true;
    }
    else if (ac < 4)
    {
        std::cout << "No string to replace with" << std::endl;
        return true;
    }
    return false;
}

void replace_in_file(const std::string &filename, const std::string &to_replace, const std::string &replacement)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Could not open the file!" << std::endl;
		return;
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string content = buffer.str();
	file.close();

	std::string new_content;
	size_t pos = 0;
	size_t prev_pos = 0;
	while ((pos = content.find(to_replace, pos)) != std::string::npos)
	{
		new_content.append(content, prev_pos, pos - prev_pos);
		new_content.append(replacement);
		pos += to_replace.length();
		prev_pos = pos;
	}
	new_content.append(content, prev_pos, content.length() - prev_pos);

	std::ofstream out_file(filename + ".replace");
	if (!out_file.is_open())
	{
		std::cerr << "Could not open the file for writing!" << std::endl;
		return;
	}
	out_file << new_content;
	out_file.close();
}

int main(int ac, char **av)
{
	if (err_args(ac))
		return 1;

	std::string filename = av[1];
	std::string to_replace = av[2];
	std::string replacement = av[3];

	replace_in_file(filename, to_replace, replacement);

	return 0;
}