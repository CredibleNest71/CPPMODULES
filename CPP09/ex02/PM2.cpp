/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PM2.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:27:53 by mresch            #+#    #+#             */
/*   Updated: 2025/04/16 14:24:55 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PM2.hpp"

std::vector<int> jacobsthal(int upper){
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

int fordjohnson(std::vector<std::vector<int> >& arr){
    int n = arr.size();
    if (n <= 1)
        return 0;
    
    std::vector<std::vector<int> > merge;
    for (size_t i = 0; i + 1 < arr.size() - 1; i++){
        std::vector<int> temp;
        if (arr[i].front() > arr[i + 1].front()){
            temp.push_back(arr[i].front());
            temp.push_back(arr[i + 1].front());
        } else {
            temp.push_back(arr[i + 1].front());
            temp.push_back(arr[i].front());
        }
        merge.push_back(temp);
        i++;
    }

    std::vector<int> leftover;
    bool hasleftofer = n % 2;
    if (hasleftofer)
        leftover = arr[n - 1];
    
    arr = merge;

    fordjohnson(arr);
    
    std::vector<int> jacob = jacobsthal(arr.size());
    std::vector<std::vector<int> > bigger;
    std::vector<std::vector<int> > smaller;
    std::vector<int> idxes;

    // split 
    std::vector<std::vector<int> > split;
    for (size_t i = 0; i < arr.size(); i++){
        std::vector<int> a;
        std::vector<int> b;
        for (size_t j = 0; j < arr[i].size(); j++){
            if (j < arr[i].size())
                a.push_back(arr[i][j]);
            else 
                b.push_back(arr[i][j]);
        }
        split.push_back(a);
        split.push_back(b);
    }

    arr = split;
    
    //fill bigger/smaller vector
    for (size_t i = 0; i < arr.size(); i++){
        if (i % 2 == 0){
            bigger.push_back(arr[i]);
        } else {
            smaller.push_back(arr[i]);
        }
        if (i % 2 == 0)
            idxes.push_back(i / 2);
    }
    int j = 0;
    int idx = jacob[j];
    while (!smaller[idx].empty()){
        std::cout << "Inserting: " << smaller[idx].front() << " (idx: " << idx << ")"<< std::endl;
        binaryInsert(bigger, smaller, idx, idxes);
        smaller[idx].clear();
        idx--;
        if (idx < 0){
            j++;
            idx = jacob[j];
            while (idx > (int)smaller.size() - 1){
                idx--;
            }
        }
    }
    if (hasleftofer)
        binaryInsertLeftover(bigger, leftover);
        
    arr = bigger;
}

int binaryInsertLeftover(std::vector<std::vector<int> > &bigger, std::vector<int> leftover){
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
    }
    bigger.insert(bigger.begin() + left, leftover);
    return left;
}

int binaryInsert(std::vector<std::vector<int> > &bigger, std::vector<std::vector<int> > &smaller, int idx, std::vector<int> &idxes){

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
    }
    bigger.insert(bigger.begin() + left, smaller[idx]);
    for (size_t i = (size_t) left; i < idxes.size(); i++){
        idxes[i]++;
    }
    return left;
}
