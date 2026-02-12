class Solution {
public:
    bool check(vector<int>&alpha){
        int prev = -1;

        for(int i=0;i<26;i++){
            if(alpha[i]==0) continue;
            if(prev==-1){
                prev=alpha[i];
            }else{
                if(prev!=alpha[i]) return false;
            }
        }

        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();

        int len = 0;

        for(int i=0;i<n;i++){
            vector<int>alpha(26);

            for(int j=i;j<n;j++){
                alpha[s[j]-'a']++;
                if(check(alpha)){
                    len = max(len,j-i+1);
                }
            }
        }

        return len;
    }
};
