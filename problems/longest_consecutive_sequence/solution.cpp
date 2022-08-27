#include <vector>
#include <iostream>
#include <iterator>
#include <unordered_set>

class Solution {

    // My original idea was to sort the array as efficiently as possible (e.g. using counting or radix sort) which would not achieve O(n)
    // The below idea was discovered upon looking at a solution:
    // Idea:
    // 1. Store all elements in a set
    // 2. Loop over the array and start building a sequence by checking if num[i] - 1 is in the set
    // 3. Keep track of the largest sequence

    // Note: requires c++20, tested with c++20 (g++ -std=c++20 solution.cpp)

public:
    static int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> numSet = std::unordered_set<int>();

        for(int i; i < nums.size(); i++){
            numSet.insert(nums[i]);
        };

        int longestSequence = 0;
        int currentSequence = 0;

        for(int i; i < nums.size(); i++){
            if(numSet.contains((nums[i] + 1))){
                continue;
            }
            int currNum = nums[i];
            currentSequence = 1;
            while(numSet.contains(currNum - 1)){
                currNum--;
                currentSequence++;
            }
            if(currentSequence > longestSequence){
                longestSequence = currentSequence;
            }
        }
        
        return longestSequence;
    };
};

int main() {
    std::vector<int> vec = {100,4,200,1,3,2};
    int res = Solution::longestConsecutive(vec);
    std::cout << "Longest sequence: " << res << std::endl;

    return -1;
};