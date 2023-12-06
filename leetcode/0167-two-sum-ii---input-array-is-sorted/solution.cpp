class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1=1, index2=numbers.size();
        while(index1<index2){
            if(numbers[index1-1]+numbers[index2-1]>target)index2--;
            else if(numbers[index1-1]+numbers[index2-1]==target)break;
            else index1++;
        }
        vector<int>ans={index1,index2};
        return ans;
    }
};
