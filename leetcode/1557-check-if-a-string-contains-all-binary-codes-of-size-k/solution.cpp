class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        vector<int>mark(1<<k);
        
        int mask = (1<<k)-1;
        int num=0;

        for(int i=0;i<n;i++){
            num = ((num<<1) & mask) | (s[i]-'0');
            if(i>=k-1){
                mark[num]=1;
            }
        }

        for(auto ele:mark){
            if(!ele) return false;
        }

        return true;
    }
};
