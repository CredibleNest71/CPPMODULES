/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:24:51 by mresch            #+#    #+#             */
/*   Updated: 2024/10/16 14:12:29 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H
# include <iostream>
# include <cstring>

class WrongAnimal {
public:
    WrongAnimal();
    virtual ~WrongAnimal();
    WrongAnimal(const WrongAnimal&);

    WrongAnimal operator=(const WrongAnimal&);

    std::string getType() const;
    virtual void makeSound() const;
    
protected:
    std::string type;
};

#endif