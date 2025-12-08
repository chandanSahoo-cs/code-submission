class Solution {
public:
    string convert(string s, int n) {
        if(n==1) return s;
        vector<vector<char>>store(n);

        int r=0;

        bool flag=false;

        for(auto ele:s){
            if(!flag){
                store[r].push_back(ele);
                if(r==n-1){
                    r--;
                    flag=true;
                }else r++;
            }else{
                store[r].push_back(ele);
                if(r==0){
                    r++;
                    flag=false;
                }else r--;
            }
        }

        string ans = "";

        for(int i=0;i<n;i++){
            for(auto ele:store[i]){
                ans.push_back(ele);
            }
        }

        return ans;
    }
};
