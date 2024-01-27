class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& arr) {
        auto mx = std::max_element(arr.begin(), arr.end());
        return std::distance(arr.begin(), mx);
    }
};

