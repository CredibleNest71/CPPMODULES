/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PM.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:12:02 by mresch            #+#    #+#             */
/*   Updated: 2025/04/16 10:02:07 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PM.hpp"

PM::PM() {}
PM::PM(const PM& other) {
    *this = other;
}
PM::~PM() {}
PM& PM::operator=(const PM& other) {
    if (this != &other) {
        this->_v = other._v;
        this->_d = other._d;
    }
    return *this;
}
void PM::readInput(const std::string& input) {
    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        try {
            int value = std::stoi(token);
            _v.push_back(value);
            _d.push_back(value);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input: " << token << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Out of range: " << token << std::endl;
        }
    }
}
// void PM::printVector() {
//     for (size_t i = 0; i < _v.size(); ++i) {
//         std::cout << _v[i] << " ";
//     }
//     std::cout << std::endl;
// }

// void PM::printDeque() {
//     for (size_t i = 0; i < _d.size(); ++i) {
//         std::cout << _d[i] << " ";
//     }
//     std::cout << std::endl;
// }
void PM::makePairFromVec(){
    for (size_t i = 0; i < v.size(); i++){
        Pair temp;
        temp.head = v[i];
        temp.first = &v[i];
        temp.second = NULL;
        p.push_back(temp);
    }
}


void PM::mergeInsert(std::vector<Pair>& p){
    std::vector<Pair> level;
    //make pairs
    for (size_t i = 0; i < p.size(); i++){
        Pair temp;
        if (i == p.size() - 1){
            level.push_back(p[i]);
            break;
        }
        if (p[i].head > p[i+1].head){
            temp.head = p[i].head;
            temp.first = &p[i];
            temp.second = &p[i+1];
        }
        else{
            temp.head = p[i+1].head;
            temp.first = &p[i+1];
            temp.second = &p[i];
        }
        level.push_back(temp);
        i++;
    }
}#include "PM.hpp"

int jacobshal(int upper){
    std::vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    while(nums.last < upper){
        int next = (nums[nums.size()-1] + 2 * nums[nums.size()-2]
        nums.push_back(next);
    }
}

int fordjohnson(std::vector<int>& arr){
    int n = arr.size();
    if (n <= 0)
        return 0;

    std::vector<pair<int, int>> pairs;
    std::vector<int> bigger;
    std::vector<int> smaller;


    //make pairs
    for (int i = 0; i < n; i+=2){
        std::pair p;
        if (arr[i] > arr[i+1]){
            p.first = arr[i];
            p.second = arr[i+1];
        } else {
            p.first = arr[i+1];
            p.second = arr[i];
        } 
        pairs.push_back(p);
    }

    int leftover = -1;
    bool hasleftofer = n % 2;
    if (hasleftofer)
        leftover = arr[n - 1];

    //fill bigger/smaller vector
    for (int i = 0; i < pairs.size(); i++){
        bigger.push_back(pairs[i].first);
        smaller.push_back(pairs[i].second);
    }

    fordjohnson(bigger);

    binaryInsert(bigger, smaller[0]);
}