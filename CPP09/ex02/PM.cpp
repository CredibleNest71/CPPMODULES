#include "PM.hpp"

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