#define ll long long

class Solution {
public:
    static vector<ll>odd,even;
    static bool built;

    static ll create(ll p, ll t){
        while(t){
            p = p*10+t%10;
            t/=10;
        }

        return p;
    }

    static void build(){
        if(built) return;
        for(int i=1;i<=99999;i++){
            ll p1 = create(i,i/10);
            ll p2 = create(i,i);

            if(p1<=1e9){
                if(p1&1) odd.push_back(p1);
                else even.push_back(p1);
            }

            if(p2<=1e9){
                if(p2&1) odd.push_back(p2);
                else even.push_back(p2);
            }
        }

        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());

        built = true;
        return;
    }

    ll minOperations(vector<int>& nums) {
        int n = nums.size();
        build();
        unordered_map<int,int>mp;

        ll cnt = 0;
        for(ll i=0;i<n;i++){
            if(!mp.count(nums[i])){
                auto &vec = nums[i]&1?odd:even;
                auto it = upper_bound(vec.begin(),vec.end(),nums[i]);

                ll curr = LLONG_MAX;

                if(it!=vec.end()){
                    curr = min(curr,0LL+(*it)-nums[i]);
                }
                if(it!=vec.begin()){
                    curr = min(curr,0LL+nums[i]-(*prev(it)));
                }
                mp[nums[i]] = curr/2;
            }
            
            cnt+=mp[nums[i]];
        }

        return cnt;  
    }
};

vector<ll> Solution::odd;
vector<ll> Solution::even;
bool Solution::built = false;
