/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PM2.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:28:03 by mresch            #+#    #+#             */
/*   Updated: 2025/04/16 13:28:38 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PM_HPP
# define PM_HPP
 
# include <iostream>
# include <vector>
# include <string>
# include <deque>
# include <algorithm>
# include <stdexcept>
# include <sstream> // Added for std::istringstream
# include <utility> // Added for std::pair

class PM {
public:
    // Canonical form
    PM();
    PM(const PM& other);
    ~PM();
    PM& operator=(const PM& other);

    int readInput(const std::string& input) ;
    std::vector<int> jacobshal(int upper);
    
    int fordjohnson(std::vector<int>& arr);
    int binaryInsert(std::vector<int>& arr, int value, std::vector<std::pair<int, int> >& pairs);

    int binaryInsertD(std::deque<int>& arr, int value, std::deque<std::pair<int, int> >& pairs);
    int fordjohnsonD(std::deque<int>& arr);
    
    void printVector(std::vector<int>& v, int limit);
    void printDeque(std::deque<int>& d, int limit);
            
            
    std::vector<int> _v;
    std::deque<int> _d;
};

#endif