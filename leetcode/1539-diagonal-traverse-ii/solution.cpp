class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        queue<pair<int,int>>qp;
        qp.push({0,0});

        vector<int>ans; 

        while(!qp.empty()){
            pair<int,int>p = qp.front();
            qp.pop();

            int r = p.first;
            int c = p.second;
            ans.push_back(nums[r][c]);

            if(r+1<nums.size() && c==0){
                qp.push({r+1,c});
            }

            if(c+1<nums[r].size()){
                qp.push({r,c+1});
            }
        }

        return ans;
    }
};
