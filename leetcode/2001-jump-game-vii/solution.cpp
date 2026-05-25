class Solution {
public:
    int valid(int l, int r, vector<int>&reach, int prev){

        if(l>0) prev-=reach[l-1];
        if(r>=0) prev+=reach[r];

        return prev;
    }

    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        int l = -maxJump, r = -minJump;

        vector<int>reach(n);
        reach[0]=1;
        int prev = 0;

        for(int i=0;i<n;i++){
            int curr = valid(l,r,reach,prev);
            if(s[i]=='0' && curr>0) reach[i]=1;
            prev = curr;
            l++;
            r++;
        }

        return reach[n-1];
    }
};
