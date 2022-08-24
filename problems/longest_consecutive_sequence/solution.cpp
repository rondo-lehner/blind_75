#include <map>
#include <vector>
#include <iostream>
#include <iterator>

class Solution {

    // Idea (sub-optimal as the time complexity is larger than O(n) as it depends on the range of possible values) 
    // 1. Initialise an array of length equal to the range between the min and max value in the given array (assuming this value is provided)
    // 2. Iterate over 'nums' and store 1 at the index corresponding with the current number
    // 3. Iterate over the "hash map" array and track the starting index and length of the longest consecutive sequence of 1s

public:
    static int longestConsecutive(std::vector<int>& nums) {
        std::map<int, int> hashMap = std::map<int,int>();

        for(int i; i < nums.size(); i++){
            hashMap[nums[i]] = 1;
        };

        for (auto const& x : hashMap){
            std::cout << x.first << std::endl;
        };
        
        return -1;
    };
};

int main() {
    std::vector<int> vec = {0,3,7,2,5,8,4,6,0,1};
    Solution::longestConsecutive(vec);

    return -1;
};