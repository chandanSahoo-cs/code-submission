class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int z = 0;

        set<int>even,odd;

        for(int i=0;i<n;i++){
            if(i%2) odd.insert(i);
            else even.insert(i);

            z+=(s[i]=='0');
        }

        vector<int>ops(n+1,-1);

        queue<int>q;
        q.push(z);
        ops[z]=0;

        if(z%2) odd.extract(z);
        else even.extract(z);

        while(!q.empty()){
            int zn = q.front();
            if(zn==0){
                return ops[zn];
            }
            q.pop();

            int mxr = zn+k-2*(max(0,zn+k-n)); // sabse km minus
            int mnr = zn+k-2*(min(zn,k)); // sbse zayda minus

            // cout<<mxr<<" "<<mnr<<"\n";

            set<int>&st = (mxr&1)?odd:even;

            for(auto it = st.lower_bound(mnr);it!=st.end() && *it<=mxr;){
                int val = *it;

                if(ops[val]==-1){
                    ops[val] = ops[zn]+1;
                    q.push(val);
                }
                
                it = st.erase(it);

            }

        }

        return -1;
    }
};

/*
n = len of str
z = number of zeroes
f = number of zerores taken
zn = z+(k-f)-f
zn = z+k-2*f;

f <= min(z,k)
k-f<=n-z

-f<=n-z-k
f>=z+k-n
*/



