/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:42:32 by mresch            #+#    #+#             */
/*   Updated: 2024/11/14 10:37:30 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H
# include <iostream>
# include <cstring>
# include "WrongAnimal.h"

class WrongCat : public WrongAnimal{

public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat& goodboy);

    WrongCat& operator=(const WrongCat& goodboy);

    void makeSound()const;
};

#endif
