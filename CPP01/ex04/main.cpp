/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:06:16 by codespace         #+#    #+#             */
/*   Updated: 2024/10/21 13:16:50 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>
#include <cctype>

std::string myreplace(std::string str, std::string s1, std::string s2){
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
	ret.append(str, prev, str.length() - prev);
	//ret.append(str, prev, std::string::npos);

	return ret;
}

int	check_str(char *str){
	int	i = 0;
	while (str[i]){
		if (!isalnum(str[i]))
			if (str[i] != '.' && str[i] != '_')
				return (1);
		i++;
	}
	return (0);
}

int	check_input(int ac, char **av){
    if (ac != 4){
	std::cout << "incorrect input\n";
	return 1;
	}
	if (check_str(av[1])){
		std::cout << "Invalid input\n";
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (check_input(ac,av))
		return (1);

	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	std::string	line;

	std::ifstream	infile(filename.c_str());
	if (!infile.is_open()){
		std::cout << "Error opening input file\n";
		return 1;
	}
	
	std::string output_filename = filename + ".replace";
	std::ofstream	outfile(output_filename.c_str());
	if (!outfile.is_open()){
		std::cout << "Error opening output file\n";
		infile.close();
		return 1;
	}

	while (std::getline(infile, line)){
		line = myreplace(line, s1, s2);
		outfile << line << std::endl;
	}
	
	infile.close();
	outfile.close();
	return 0;
}
