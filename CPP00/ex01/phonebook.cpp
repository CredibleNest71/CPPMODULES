/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:26:45 by mresch            #+#    #+#             */
/*   Updated: 2024/06/12 11:50:42 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CPP
# define PHONEBOOK_CPP
# include <string>
# include <iostream>
# include <cstring>
# include <iomanip>
# include "phonebook.hpp"
# include "contact.hpp"

PhoneBook::PhoneBook(void){
	this->idx = 0;
	for (int i = 0; i < 8; i++){
		this->contacts[i].firstname = "";
	}
}

void	createcontact(Contact *contact){
	std::cout << "Enter first name: ";
	std::getline(std::cin>>std::ws, contact->firstname);
	std::cout << std::endl << "Enter last name: ";
	std::getline(std::cin, contact->lastname);
	std::cout << std::endl << "Enter nickname: ";
	std::getline(std::cin, contact->nickname);
	std::cout << std::endl << "Enter telephone number: ";
	std::getline(std::cin, contact->telnr);
	std::cout << std::endl << "Enter darkest secret: ";
	std::getline(std::cin, contact->secret);
	std::cout << std::endl;
	return;
}

void	PhoneBook::add(){
	Contact	*curr;
	curr = &this->contacts[idx];
	idx = (idx + 1) % 8;
	createcontact(curr);
}

void	printten(const std::string content){
	int	length;
	length = content.length();
	if (length < 0)
		return;
	if (length > 10)
	{
		std::cout << content.substr(0, 9);
		std::cout << ".";
	}
	else
		std::cout << std::setw(10) << content;
}

void	printcontact(const Contact *con){
	if (con->firstname == "")
		return ;
	printten(con->firstname);
	std::cout << "|";
	printten(con->lastname);
	std::cout << "|";
	printten(con->nickname);
	// std::cout << "|";
	// printten(con->secret);
	std::cout << std::endl;
}

void	display_contact(const Contact *con){
	if (con->firstname == "")
		return ;
	std::cout << "FIRST NAME:	" << con->firstname << std::endl;
	std::cout << "LAST NAME:	"<< con->lastname << std::endl;
	std::cout << "NICK NAME:	"<< con->nickname << std::endl;
	std::cout << "TELEPHONE NR:	"<< con->telnr << std::endl;
	std::cout << "DARKEST SECRET:	"<< con->secret << std::endl << std::endl;
}

void	PhoneBook::search(void){
	std::string	idx;
	Contact		*curr;
	for (int i = 0; i < 8; i++){
		curr = &this->contacts[i];
		if (curr->firstname == "")
			break;
		std::cout << i << " |";
		printcontact(curr);
	}
	std::cout << "Enter Index: ";
	std::cin >> idx;
	std::cout << std::endl;
	curr = &this->contacts[atoi(&idx[0]) % 8];
	if (curr->firstname == "")
		std::cout << "CONTACT NOT FOUND" << std::endl << std::endl;
	else 
		display_contact(curr);
}
#endif
