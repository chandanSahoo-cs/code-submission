class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int curr1=-1e9+7,curr2=-1e9+7,cnt1=0,cnt2=0;

        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=curr2){
                curr1=nums[i];
                cnt1=1;
            }else if(cnt2==0 && nums[i]!=curr1){
                curr2 = nums[i];
                cnt2=1;
            }else if(nums[i]==curr1) cnt1++;
            else if(nums[i]==curr2) cnt2++;
            else cnt1--,cnt2--;
        }

        int occur1=0,occur2=0;

        for(int i=0;i<n;i++){
            if(nums[i]==curr1) occur1++;
            if(nums[i]==curr2) occur2++;
        }

        vector<int>ans;

        if(occur1>n/3) ans.push_back(curr1);
        if(occur2>n/3) ans.push_back(curr2);

        return ans;
    }
};
