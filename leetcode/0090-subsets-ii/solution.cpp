class Solution {
public:
    vector<vector<int>>ans;

    void fill(vector<int>&a, int i,vector<int>&s,int skip){
        if(a.size()==i){
            ans.push_back(s);
            return;
        }

        if(a[i]==skip){
            fill(a,i+1,s,skip);
            return;
        }
        s.push_back(a[i]);
        fill(a,i+1,s,11);
        s.pop_back();
        fill(a,i+1,s,a[i]);

        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>s;
        fill(nums, 0,s,11);
        return ans;
    }
};
