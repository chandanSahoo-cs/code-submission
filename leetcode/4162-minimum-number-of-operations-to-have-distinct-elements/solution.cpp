class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int>uniq(n);
        set<int>st;
        

        for(int i=n-1;i>=0;i-- ){
            st.insert(nums[i]);
            uniq[i] = st.size();
        }

        int j=0;

        int cnt=0;
        
        while(j<n){
            if(n-j>uniq[j]){
                cnt++;
                j+=3;
            }else break;
        }

        return cnt;
    }
};
