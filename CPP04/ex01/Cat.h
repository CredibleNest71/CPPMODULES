/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:42:32 by mresch            #+#    #+#             */
/*   Updated: 2024/10/18 15:40:47 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H
# include <iostream>
# include <cstring>
# include "Animal.h"
# include "Brain.h"


class Cat : public Animal{
private:
    Brain*   brain;
public:
    Cat();
    ~Cat();
    Cat(const Cat& goodboy);

    Cat operator=(const Cat& goodboy);

    void makeSound()const override;
};

#endif
