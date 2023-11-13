// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         auto maxEle=max_element(nums.begin(),nums.end());
//         if(*maxEle==1) return 2;
//         if(*maxEle<=0) return 1;
//         if(nums.size()==1){
//             if(nums[0]<=0)return 1;
//             if(nums[0]==1) return 2;
//         }
//         if(nums[0]>0) return 1;
//         for(int i=1;i<nums.size()-1;i++){
//             if(nums[i]!=nums[i-1]+1 && nums[i-1]+1>0) return nums[i-1]+1;
//         }
//         return nums[nums.size()-1]+1;
//     }
// };

#include <iostream>
#include <vector>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();

        // Cyclic sort
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all elements are in their correct positions, return the next positive integer
        return n + 1;
    }
};




