/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:49:56 by mresch            #+#    #+#             */
/*   Updated: 2025/03/28 11:04:32 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN(){}
RPN::~RPN(){}
static int isOperand(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::parse(const std::string& input){
    int num;

    size_t i = 0;
    while (input[i]) {
        if (std::isdigit(input[i])) {
            num = input[i] - '0';
            num_stack.push(num);
            //std::cout << "numstack top:" << num_stack.top() << std::endl;
            if (input[i + 1] != '\0' && input[i + 1] != ' ') {
                throw std::invalid_argument("Invalid input: No space between numbers and operands");
            }
        }
        else if (isOperand(input[i])) {
            if (num_stack.size() < 2 || operand_stack.size() + 1 >= num_stack.size()) {
                throw std::invalid_argument("Operands have to follow numbers");
            }
            operand_stack.push(input[i]);
            //std::cout << "operandstack top:" << operand_stack.top() << std::endl;
            if (input[i + 1] != '\0' && input[i + 1] != ' ') {
                throw std::invalid_argument("Invalid input: No space between numbers and operands");
            }
        }
        else if (input[i] != ' ') {
            throw std::invalid_argument("Invalid input");
        }
        i++;
    }
    return 0;
}

int RPN::calculate(){
    flipStack(num_stack);
    flipStack(operand_stack);
    if (num_stack.size() - 1 != operand_stack.size()) {
        std::cerr << "Invalid Input: Number to Operand Ratio is off ";
        std::cerr << num_stack.size() << ":" << operand_stack.size() << std::flush;
        throw std::invalid_argument("");
    }
    if (num_stack.empty()) {
        throw std::invalid_argument("No numbers to calculate");
    }
    if (operand_stack.empty()) {
        throw std::invalid_argument("No operands to calculate");
    }
    long long int result = num_stack.top();
    num_stack.pop();
    while (!operand_stack.empty() && !num_stack.empty()) {
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
        if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Result is out of bounds");
        }
        num_stack.pop();
        operand_stack.pop();
    }
    return (int) result;
}
