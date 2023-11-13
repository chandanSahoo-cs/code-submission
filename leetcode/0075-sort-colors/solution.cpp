class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Bubble Sort
        // for(int j=0;j<nums.size();j++){
        //     bool flag=false;
        //     for(int i=1;i<nums.size();i++){
        //         if(nums[i]<nums[i-1]){
        //             swap(nums[i],nums[i-1]);
        //             flag=true;
        //         }
        //     }
        //     if(!flag) break;
        // }

        //Selection Sort
        // for(int i=0;i<nums.size();i++){
        //     auto minEle=min_element(nums.begin()+i,nums.end());
        //     int minIndex=distance(nums.begin(),minEle);
        //     swap(nums[i],nums[minIndex]);
        // }

        // Insertion Sort
        for(int i=1;i<nums.size();i++){
            int value=nums[i];
            int j=i-1;
            while(j>=0 && nums[j]>value){
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=value;
        }
        return;
    }
};
