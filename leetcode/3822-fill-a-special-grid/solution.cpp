class Solution {
public:
    vector<vector<int>>ans;

    void rec(int rl, int rr, int cl, int cr, int val){
        if(rl==rr && cl==cr){
            ans[rl][cl] = val;
            return;
        }

        int cmid = (cl+cr)/2;
        int rmid = (rl+rr)/2;

        int div = ((cr-cl+1)*(rr-rl+1))/4;

        // top-right
        rec(rl,rmid,cmid+1,cr,val);
        
        // bottom-right
        rec(rmid+1,rr,cmid+1,cr,val+div);

        // bottom-left
        rec(rmid+1,rr,cl,cmid,val+2*div);

        // top-left;
        rec(rl,rmid,cl,cmid,val+3*div);

        return;
    }

    vector<vector<int>> specialGrid(int n) {
        ans.assign(1<<n,vector<int>(1<<n));
        rec(0,(1<<n)-1,0,(1<<n)-1,0);

        return ans;    
    }
};
