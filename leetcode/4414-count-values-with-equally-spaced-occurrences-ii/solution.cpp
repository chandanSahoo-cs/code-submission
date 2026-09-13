class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int cnt = 0;
        
        for(auto [_,value]:mp){
            if(value.size()<3) continue;

            int m = value.size();

            unordered_set<int>st;

            for(int i=1;i<m;i++){
                st.insert(value[i]-value[i-1]);
                if(st.size()>1) break;
            }

            cnt+=(st.size()==1);
        }

        return cnt;
    }
};
