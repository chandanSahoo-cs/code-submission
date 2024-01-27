#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int> store;
        int size1 = nums1.size(), size2 = nums2.size();
        int i = 0, j = 0;
        
        while (i < size1 && j < size2) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                // Found intersection, add to store
                store.push_back(nums1[i]);
                // Skip duplicates
                while (i + 1 < size1 && nums1[i] == nums1[i + 1]) ++i;
                while (j + 1 < size2 && nums2[j] == nums2[j + 1]) ++j;
                ++i;
                ++j;
            }
        }
        
        return store;
    }
};

