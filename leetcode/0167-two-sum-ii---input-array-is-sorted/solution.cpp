class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s=1, e=numbers.size();
        while(s<e){
            int mid=s+(e-s)/2;
            if(numbers[s-1]+numbers[e-1]<target) s++;
            else if(numbers[s-1]+numbers[e-1]>target) e--;
            else break;
        }
        return {s,e};
    }
};
