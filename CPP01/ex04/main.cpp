/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:06:16 by codespace         #+#    #+#             */
/*   Updated: 2024/06/14 13:49:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

std::string replace(std::string str, std::string s1, std::string s2){
    std::string	ret;
	size_t		pos = 0;
	size_t		prev = 0;

	while (str.find(s1, pos) != std::string::npos){
		pos = str.find(s1, pos);
		ret.append(str, prev, pos - prev);
		ret.append(s2);
		pos += s1.length();
		prev = pos;
	}
	ret.append(str, prev, std::string::npos);

	return ret;
}

int main(int ac, char **av)
{
    if (ac != 4){
		std::cout << "incorrect input\n";
		return 1;
	}
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	std::ifstream	infile(filename);
	if (!infile.is_open()){
		std::cout << "Error opening input file\n";
		return 1;
	}
	
	std::ofstream	outfile(filename + ".replace");
	if (!outfile.is_open()){
		std::cout << "Error opening output file\n";
		infile.close();
		return 1;
	}

	std::string	line;
	while (std::getline(infile, line)){
		line = replace(line, s1, s2);
		outfile << line << std::endl;
	}
	
	infile.close();
	outfile.close();
	return 0;
}