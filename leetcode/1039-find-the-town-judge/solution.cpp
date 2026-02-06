class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int>indegree(n+1);
        vector<int>outdegree(n+1);

        for(auto &ele:trust){
            indegree[ele[1]]++;
            outdegree[ele[0]]++;
        }

        for(int i=1;i<=n;i++){
            if(indegree[i]==n-1 && outdegree[i]==0) return i;
        }
        return -1;
    }
};
