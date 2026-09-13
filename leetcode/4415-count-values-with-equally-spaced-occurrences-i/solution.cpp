class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>store(101);

        for(int i=0;i<n;i++){
            store[nums[i]].push_back(i);
        }

        int cnt = 0;
        
        for(int i=1;i<=100;i++){
            if(store[i].size()!=3) continue;
            int a = store[i][0], b = store[i][1], c = store[i][2];

            if(b-a==c-b) cnt++;
        }

        return cnt;
    }
};
