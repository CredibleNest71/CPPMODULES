/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:58:11 by mresch            #+#    #+#             */
/*   Updated: 2025/01/10 15:34:44 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H
#include <iostream>
#include <cstdlib> 
#include <ctime>


class Base {
public:
    virtual ~Base();
};

class A : public Base {
public:
    A(){};
};
class B : public Base {
public:
    B(){};
};
class C : public Base {
public:
    C(){};
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);


#endif