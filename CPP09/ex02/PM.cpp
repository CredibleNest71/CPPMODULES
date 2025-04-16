/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PM.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:12:02 by mresch            #+#    #+#             */
/*   Updated: 2025/04/16 12:55:43 by mresch           ###   ########.fr       */
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
int PM::readInput(const std::string& input) {
    if (input.empty() || input.find_first_not_of("0123456789 ") != std::string::npos) {
        std::cerr << "Error: Faulty Input" << std::endl;
        return 1;
    }
    std::istringstream iss(input);
    int token;
    while (iss >> token) {
        try {
            int value = token;
            if (value < 0){
                std::cerr << "Error: Negative number: " << value << std::endl;
                return 1;
            }
            _v.push_back(value);
            _d.push_back(value);
        } catch(...) {
            std::cerr << "Error: Invalid input" << std::endl;
            return 1;
        }
    }
    return 0;
}
void PM::printVector(std::vector<int>& v, int limit) {
    if (limit < 0 || limit > (int)v.size()) {
        limit = v.size();
    }
    int i = 0;
    while (i < limit) {
        std::cout << v[i] << " ";
        i++;
    }
    if (i < (int)v.size()) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void PM::printDeque(std::deque<int>& d, int limit) {
    if (limit < 0 || limit > (int) d.size()) {
        limit = d.size();
    }
    int i = 0;
    while (i < limit) {
        std::cout << d[i] << " ";
        i++;
    }
    if (i < (int)d.size()) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

std::vector<int> PM::jacobshal(int upper){
    std::vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    while(nums.back() < upper){
        int next = (nums[nums.size()-1] + 2 * nums[nums.size()-2]);
        nums.push_back(next);
    }
    nums.erase(nums.begin() + 1);
    return nums;
}

int PM::binaryInsert(std::vector<int>& arr, int value, std::vector<std::pair<int, int> >& pairs) {
    int left = 0;
    int right = arr.size() - 1;
    int match = -1;
    
    for (size_t i = 0; i < pairs.size(); i++) {
        if (pairs[i].second == value) {
            match = pairs[i].first;
            break;
        }
    }
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == match) {
            right = i;
            break;
        }
    }
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    arr.insert(arr.begin() + left, value);
    return left;
}

int PM::fordjohnson(std::vector<int>& arr){
    int n = arr.size();
    if (n <= 1)
        return 0;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> bigger;
    std::vector<int> smaller;

    //make pairs
    for (int i = 0; i + 1 < n; i+=2){
        std::pair<int, int> p;
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
    for (size_t i = 0; i < pairs.size(); i++){
        bigger.push_back(pairs[i].first);
        smaller.push_back(pairs[i].second);
    }
    
    fordjohnson(bigger);
    
    // std::cout << "Bigger: ";
    // printVector(bigger);
    // std::cout << "Smaller: ";
    // printVector(smaller);
    // if (hasleftofer){
    //     std::cout << "Leftover: " << leftover << std::endl;
    // }

    std::vector<int> jacob = jacobshal(bigger.size());
    int idx = jacob[0];
    int j = 0;
    while (smaller[idx] != -1){
        // std::cout << "Inserting: " << smaller[idx] << " (idx: " << idx << ")"<< std::endl;
        binaryInsert(bigger, smaller[idx], pairs);
        smaller[idx] = -1;
        idx--;
        if (idx < 0 || smaller[idx] == -1){
            j++;
            idx = jacob[j];
            while (idx > (int)smaller.size() - 1){
                idx--;
            }
        }
    }
    if (hasleftofer)
        binaryInsert(bigger, leftover, pairs);

    // std::cout << "Sorted: " << std::endl;
    // printVector(bigger);
    // std::cout << "___________________________________________" << std::endl;
    arr = bigger;
    return 0;
}

//DEQUE 


int PM::binaryInsertD(std::deque<int>& arr, int value, std::deque<std::pair<int, int> >& pairs) {
    int left = 0;
    int right = arr.size() - 1;
    int match = -1;
    
    for (size_t i = 0; i < pairs.size(); i++) {
        if (pairs[i].second == value) {
            match = pairs[i].first;
            break;
        }
    }
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == match) {
            right = i;
            break;
        }
    }
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    arr.insert(arr.begin() + left, value);
    return left;
}

int PM::fordjohnsonD(std::deque<int>& arr){
    int n = arr.size();
    if (n <= 1)
        return 0;

    std::deque<std::pair<int, int> > pairs;
    std::deque<int> bigger;
    std::deque<int> smaller;

    //make pairs
    for (int i = 0; i + 1 < n; i+=2){
        std::pair<int, int> p;
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
    for (size_t i = 0; i < pairs.size(); i++){
        bigger.push_back(pairs[i].first);
        smaller.push_back(pairs[i].second);
    }
    
    fordjohnsonD(bigger);
    
    // std::cout << "Bigger: ";
    // printDeque(bigger);
    // std::cout << "Smaller: ";
    // printDeque(smaller);
    // if (hasleftofer){
    //     std::cout << "Leftover: " << leftover << std::endl;
    // }

    std::vector<int> jacob = jacobshal(bigger.size());
    int idx = jacob[0];
    int j = 0;
    while (smaller[idx] != -1){
        // std::cout << "Inserting: " << smaller[idx] << " (idx: " << idx << ")"<< std::endl;
        binaryInsertD(bigger, smaller[idx], pairs);
        smaller[idx] = -1;
        idx--;
        if (idx < 0 || smaller[idx] == -1){
            j++;
            idx = jacob[j];
            while (idx > (int)smaller.size() - 1){
                idx--;
            }
        }
    }
    if (hasleftofer)
        binaryInsertD(bigger, leftover, pairs);

    // std::cout << "Sorted: " << std::endl;
    // printDeque(bigger);
    // std::cout << "___________________________________________" << std::endl;
    arr = bigger;
    return 0;
}