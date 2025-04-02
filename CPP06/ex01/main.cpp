/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:33:34 by mresch            #+#    #+#             */
/*   Updated: 2025/01/09 12:00:42 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

int main(){
    struct Data data = {"eyyy", 1, 2, 3};
    
    uintptr_t ptr = Serializer::serialize(&data);
    struct Data *data_ptr = Serializer::deserialize(ptr);
    
    std::cout << "before serialization:" << std::endl;
    std::cout << data.str << std::endl;
    std::cout << data.field1 << std::endl;
    std::cout << data.field2 << std::endl;
    std::cout << data.field3 << std::endl;
    std::cout << "_________________________________" << std::endl;

    std::cout << "after serialization:" << std::endl;
    std::cout << (*data_ptr).str << std::endl;
    std::cout << (*data_ptr).field1 << std::endl;
    std::cout << (*data_ptr).field2 << std::endl;
    std::cout << (*data_ptr).field3 << std::endl;
    std::cout << "_________________________________" << std::endl;
    
    
    return 0;
}