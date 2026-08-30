class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>freq(101);

        for(int i=0;i<n;i++){
            freq[nums[i]].push_back(i);
        }

        int cnt = 0;

        for(int i=0;i<101;i++){
            if(freq[i].size()==0) continue;
            bool flag = true;
            for(int j=1;j<freq[i].size();j++){
                if(freq[i][j]!=freq[i][j-1]+1){
                    flag=false;
                    break;
                }
            }

            if(flag) cnt++;
        }

        return cnt;
    }
};
