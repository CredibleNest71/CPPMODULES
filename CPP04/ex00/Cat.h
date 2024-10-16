/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:42:32 by mresch            #+#    #+#             */
/*   Updated: 2024/10/16 14:15:17 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H
# include <iostream>
# include <cstring>
# include "Animal.h"

class Cat : public Animal{

public:
    Cat();
    ~Cat();
    Cat(const Cat& goodboy);

    Cat operator=(const Cat& goodboy);

    void makeSound()const override;
};

#endif
