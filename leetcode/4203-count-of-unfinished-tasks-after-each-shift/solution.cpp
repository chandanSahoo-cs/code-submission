#define ll long long 
class Solution {
public:

    ll search(vector<ll>&pref, ll used, ll l, ll trg){
        ll n = pref.size();

        ll r = n-1;
        ll ans = n;

        while(l<=r){
            ll m = l+(r-l)/2;
            if(pref[m]-used>trg){
                r = m-1;
                ans = m;
            }else l = m+1;
        }

        return ans;
    }

    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        ll n = tasks.size(), m = shifts.size();

        vector<ll>pref(n+1);

        for(ll i=0;i<n;i++){
            pref[i+1] = pref[i]+tasks[i];
        }

        ll carry = 0;
        ll curr = 0;
        
        vector<int>ans;

        for(ll i=0;i<m;i++){
            if(carry>shifts[i]){
                carry-=shifts[i];
            }else{
                ll trg = shifts[i]-carry;
                if(carry>0){
                    curr++;
                    carry = 0;
                    if(curr==n){
                        ans.push_back(0);
                        continue;
                    }
                }
                
                ll idx = search(pref,pref[(curr)%n],(curr+1)%n,trg);

                if(idx>0){
                    trg -= pref[idx-1]-pref[(curr)%n];
                    curr = idx-1;
                }

                if(trg>0 && idx<n+1){
                    carry = tasks[idx-1]-trg;
                }
            }
            ans.push_back(n-curr);
        }

        return ans;
    }
};
