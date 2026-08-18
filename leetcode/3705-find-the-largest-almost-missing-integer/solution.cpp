class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mark(51);

        for(int i=0;i<n-k+1;i++){
            vector<int>vis(51);
            for(int j=i;j<i+k;j++){
                if(!vis[nums[j]]){
                    mark[nums[j]]++;
                    vis[nums[j]]=1;
                }
            }
        }

        for(int i=50;i>=0;i--){
            if(mark[i]==1) return i;
        }

        return -1;
    }
};
