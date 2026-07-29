#define ll long long

class Solution {
public:
    static const ll CAP = 2000000;

    ll nCr(ll a, ll b){
        if(b < 0 || b > a) return 0;
        b = min(b, a - b);
        ll res = 1;
        for(ll j = 1; j <= b; j++){
            res = res * (a - b + j) / j;   
            if(res > CAP) return CAP;      
        }
        return res;
    }

    ll compute(int n, vector<int>& freq){
        ll val = 1;
        int rem = n;
        for(auto ele: freq){
            if(ele == 0) continue;
            val *= nCr(rem, ele);
            rem-= ele;
            if(val > CAP) return CAP;
        }

        return val;
    }


    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int m = n/2;

        vector<int>freq(26);

        for(auto ele:s){
            freq[ele-'a']++;
        }

        // halved the freq to keep as we only want left half
        char odd='#';
        for(int i=0;i<26;i++){
            if(freq[i]&1) odd = 'a'+i;
            freq[i]/=2;
        }

        // check if even k permutations are possible

        if(compute(m,freq)<k) return "";

        // develop ans;
        string ans = "";

        for(int i=0;i<m;i++){
            for(int j=0;j<26;j++){
                if(freq[j]<=0) continue;
                freq[j]--;
                int val = compute(m-i-1,freq);
                freq[j]++;

                if(val<k){
                    k-=val;
                }else{
                    freq[j]--;
                    ans+=('a'+j);
                    break;
                }
            }
        }

        string rans = ans;
        reverse(rans.begin(),rans.end());
        
        if(odd!='#'){
            return ans+odd+rans;
        }

        return ans+rans;
    }
};
