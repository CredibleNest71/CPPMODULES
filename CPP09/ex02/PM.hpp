/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:28:03 by mresch            #+#    #+#             */
/*   Updated: 2025/04/22 16:50:48 by mresch           ###   ########.fr       */
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

extern int global;

template<typename T>
void printVec(T& v){
    for (size_t i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

template<typename NestedContainer>
void printVecVec(NestedContainer& v){
    for (size_t i = 0; i < v.size(); i++){
        printVec(v[i]);
    }
}

template<typename Container>
Container jacobsthal(int upper){
    Container nums;
    nums.push_back(0);
    nums.push_back(1);
    while(nums.back() < upper){
        int next = (nums[nums.size()-1] + 2 * nums[nums.size()-2]);
        nums.push_back(next);
    }
    nums.erase(nums.begin() + 1);
    return nums;
}

template<typename NestedContainer>
int binaryInsertLeftover(NestedContainer&bigger, typename NestedContainer::value_type leftover){
    int left = 0;
    int right = bigger.size() - 1;
    int value = leftover.front();
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (bigger[mid].front() < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        global++;
    }
    bigger.insert(bigger.begin() + left, leftover);
    return left;
}

template<typename NestedContainer>
int binaryInsert(NestedContainer &bigger, NestedContainer&smaller, int idx, typename NestedContainer::value_type &idxes){
    int left = 0;
    int right = idxes[idx];
    int value = smaller[idx].front();
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (bigger[mid].front() < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        global++;
    }
    bigger.insert(bigger.begin() + left, smaller[idx]);
    for (size_t i = 0; i < idxes.size(); i++){
        idxes[i]++;
    }
    return left;
}

template<typename NestedContainer>
int fordjohnson(NestedContainer& arr) {
    typedef typename NestedContainer::value_type value_type;
    int n = arr.size();
    if (n <= 1)
        return 0;

    NestedContainer merge;
    // Make pairs
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        value_type temp;
        if (arr[i].front() > arr[i + 1].front()) {
            global++;
            temp.insert(temp.end(), arr[i].begin(), arr[i].end());
            temp.insert(temp.end(), arr[i + 1].begin(), arr[i + 1].end());
        } else {
            temp.insert(temp.end(), arr[i + 1].begin(), arr[i + 1].end());
            temp.insert(temp.end(), arr[i].begin(), arr[i].end());
        }
        merge.push_back(temp);
    }

    value_type leftover;
    bool hasleftover = n % 2;
    if (hasleftover){
        leftover = arr[n - 1];
    }
    arr = merge;

    fordjohnson(arr);

    value_type jacob = jacobsthal<value_type>(arr.size());
    NestedContainer bigger;
    NestedContainer smaller;
    value_type idxes;

    // Split
    NestedContainer split;
    for (size_t i = 0; i < arr.size(); i++) {
        value_type a, b;
        for (size_t j = 0; j < arr[i].size(); j++) {
            if (j < arr[i].size() / 2)
                a.push_back(arr[i][j]);
            else
                b.push_back(arr[i][j]);
        }
        split.push_back(a);
        split.push_back(b);
    }

    arr = split;

    // Fill bigger/smaller vectors
    for (size_t i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            bigger.push_back(arr[i]);
            idxes.push_back(i / 2);
        } else {
            smaller.push_back(arr[i]);
        }
    }

    int j = 0;
    int idx = jacob[j];
    while (!smaller[idx].empty()) {
        binaryInsert(bigger, smaller, idx, idxes);
        smaller[idx].clear();
        idx--;
        if (idx < 0 || smaller[idx].empty()) {
            j++;
            idx = jacob[j];
            while (idx > (int)smaller.size() - 1) {
                idx--;
            }
        }
    }
    if (hasleftover)
        binaryInsertLeftover(bigger, leftover);

    arr = bigger;
    return 0;
}

#endif