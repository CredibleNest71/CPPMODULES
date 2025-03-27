/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:49:56 by mresch            #+#    #+#             */
/*   Updated: 2025/03/27 17:06:46 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static int isOperand(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::parse(const std::string& input){
    std::istringstream iss(input);
    std::string token;
    int num;

    size_t i = 0;
    while (input[i]) {
        if (std::isdigit(token[i])) {
            num = token[i] - '0';
            num_stack.push(num);
        }
        else if (isOperand(token[i])) {
            if (num_stack.size() < 2 || operand_stack.size() + 1 >= num_stack.size()) {
                throw std::invalid_argument("Operands have to follow numbers");
            }
            operand_stack.push(token[i]);
        }
        else if (token[i != ' ']) {
            throw std::invalid_argument("Invalid input");
        }
        i++;
    }
    return 0;
}



int RPN::calculate(){
    flipStack(num_stack);
    flipStack(operand_stack);
    int result = num_stack.top();
    num_stack.pop();
    while (!operand_stack.empty()) {
        switch (operand_stack.top()) {
            case '+':
                result += num_stack.top();
                break;
            case '-':
                result -= num_stack.top();
                break;
            case '*':
                result *= num_stack.top();
                break;
            case '/':
                result /= num_stack.top();
                break;
            default:
                throw std::invalid_argument("Invalid operand");
        }
        num_stack.pop();
        operand_stack.pop();
    }
    
}
