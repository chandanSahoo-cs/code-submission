class Solution {
public:
    vector<int> calcPref(vector<int>&a){
        int n = a.size();
        vector<int>pref(n);

        pref[0] = a[0];

        for(int i=1;i<n;i++){
            pref[i] = __gcd(pref[i-1],a[i]);
        }

        return pref;
    }

    vector<int> calcSuff(vector<int>&a){
        int n = a.size();
        vector<int>suff(n);

        suff[n-1] = a[n-1];

        for(int i=n-2;i>=0;i--){
            suff[i] = __gcd(suff[i+1],a[i]);
        }

        return suff;
    }

    int compute(vector<int>&a){
        int n = a.size();
        vector<int>pref = calcPref(a);
        vector<int>suff = calcSuff(a);

        int cnt = 0;
        for(int i=0;i<n-1;i++){
            if(pref[i]==suff[i+1]) cnt++;
        }

        return cnt;
    }

    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int cnt = compute(nums);

        vector<int>pref = calcPref(nums);
        vector<int>suff = calcSuff(nums);

        // special case 
        // only remove the first element;

        vector<int>b;
        for(int j=1;j<n;j++){
            b.push_back(nums[j]);
        }
        cnt = max(cnt,compute(b));

        for(int i=1;i<n;i++){
            if(pref[i]!=pref[i-1]){
                vector<int>a;
                for(int j=0;j<n;j++){
                    if(i!=j){
                        a.push_back(nums[j]);
                    }
                }
                cnt = max(cnt,compute(a));
            }
        }

        return cnt;
    }
};

/*
- as we iterate over the array the gcd will increase or remain same for the first half
and decrease or remain same for the second half

- 
*/
