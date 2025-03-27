/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:46:48 by mresch            #+#    #+#             */
/*   Updated: 2025/03/27 17:05:14 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
 
# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <stdexcept>
# include <cctype>

class RPN {
    public:
        RPN();
        ~RPN();
        RPN(const RPN& cpy);
        RPN& operator=(const RPN& og);

        int parse(const std::string& input);
        int calculate();
        
        template <typename T>
        void flipStack(std::stack<T>& stack) {
            std::stack<T> tmp;
            while (!stack.empty()) {
                tmp.push(stack.top());
                stack.pop();
            }
            stack = tmp;
        }
    private:
        std::stack<int>	    num_stack;
        std::stack<char>    operand_stack;
        std::string		    _input;
        std::string		    _output;
};

#endif // RPN_HPP