
class Solution {
public:    
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int>close(n);

        for(int i=0;i<n;i++){
            if(i==0){
                close[i] = i+1;
            }else if(i==n-1){
                close[i] = i-1;
            }else{
                int l = nums[i-1];
                int r = nums[i+1];

                if(abs(nums[i]-l)<=abs(nums[i]-r)){
                    close[i] = i-1;
                }else close[i] = i+1;
            }
        }

        vector<int>ltr(n), rtl(n);

        for(int i=1;i<n;i++){
            if(close[i-1]==i){
                ltr[i] = ltr[i-1]+1;
            }else{
                ltr[i] = ltr[i-1]+abs(nums[i-1]-nums[i]);
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(close[i+1]==i){
                rtl[i] = rtl[i+1]+1;
            }else{
                rtl[i] = rtl[i+1]+abs(nums[i+1]-nums[i]);
            }
        }


        vector<int>ans;

        for(auto &q:queries){
            int l = q[0], r = q[1];

            if(l<=r){
                ans.push_back(ltr[r]-ltr[l]);
            }else{
                ans.push_back(abs(rtl[l]-rtl[r]));
            }
        }

        return ans;
    }
};
