class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        int ans = 0;

        for(int i=0;i<n;i++){
            if(i==0) ans+=target[i];
            else{
                ans+=max(0,target[i]-target[i-1]);
            }
        }

        return ans;
    }
};
