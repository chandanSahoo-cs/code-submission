const int MX = 18;
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>foo(n);
        iota(foo.begin(),foo.end(),0);

        sort(foo.begin(),foo.end(),[&](int i, int j){
            return nums[i]<nums[j];
        });

        vector<vector<int>>mat(MX,vector<int>(n,-1));

        int k = 0;
        for(int i=0;i<n;i++){
            while(k<n && nums[foo[k]]-nums[foo[i]]<=maxDiff) k++;
            mat[0][foo[i]] = foo[k-1];
        }

        for(int i=1;i<MX;i++){
            for(int j=0;j<n;j++){
                if(mat[i-1][j]!=-1) mat[i][j] = mat[i-1][mat[i-1][j]];
                else mat[i][j] = -1;
            }
        }

        vector<int>ans;

        for(auto &ele:queries){
            int u = ele[0], v = ele[1];

            if(u==v){ 
                ans.push_back(0);
                continue;
            }

            if(nums[u]>nums[v]) swap(u,v);

            int val = 0;

            for(int i=MX-1;i>=0 && u!=-1;i--){
                if(mat[i][u]==-1) u=-1;
                else if(nums[mat[i][u]]<nums[v]){
                    u = mat[i][u];
                    val+=(1<<i);
                }
            }

            if(u==-1 || nums[mat[0][u]]<nums[v]) ans.push_back(-1);
            else ans.push_back(val+1);
        }

        return ans;
    }
};
