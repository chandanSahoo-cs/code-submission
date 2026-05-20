class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int>mark(n+1);
        vector<int>ans;

        for(int i=0;i<n;i++){
            mark[A[i]]+=1;
            mark[B[i]]+=1;

            int cnt = 0;
            for(auto ele:mark){
                if(ele==2) cnt++;
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};
