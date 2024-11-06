#define ll long long
class Solution {
public:
    int substrCntAtMostK(vector<int>& s, int k) {
        unordered_map<ll, ll> mp;
        ll n = s.size();
        ll cnt = 0;
        ll p1 = 0, p2 = 0;
        ll sub = 0, prevSize = 0;

        while (p1 <= p2 && p2 < n) {
            mp[s[p2]]++;

            if ((ll)mp.size() > k) {
                ll m = p2 - p1;
                ll d = prevSize - sub;
                cnt += ((ll)m * (m + 1)) / 2 - ((ll)d * (d + 1)) / 2;
                prevSize = m;
                sub = 0;

                while ((ll)mp.size() > k) {
                    mp[s[p1]] -= 1;
                    if (mp[s[p1]] == 0) mp.erase(s[p1]);
                    p1++;
                    sub++;
                }
            }
            p2++;
        }

        if ((ll)mp.size() <= k) {
            ll m = p2 - p1;
            ll d = prevSize - sub;
            cnt += ((ll)m * (m + 1)) / 2 - ((ll)d * (d + 1)) / 2;
        }

        return cnt; 
    }
    int subarraysWithKDistinct(vector<int>& s, int k){
        return (int)substrCntAtMostK(s, k) - (int)substrCntAtMostK(s, k - 1);
    }
};

