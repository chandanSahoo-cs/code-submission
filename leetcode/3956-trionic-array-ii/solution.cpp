#define ll long long

class Solution {
public:

    ll sum(vector<int>&nums, int l,int p, int q, int r){
        ll sum = 0;

        p--;
        q++;
        for(int i=p;i<=q;i++){
            sum+=nums[i];
        }

        p--;
        while(p>=l && sum+nums[p]>sum){
            sum+=nums[p];
            p--;
        }

        ll temp = 0;

        q++;
        while(q<=r){
            temp+=nums[q];
            q++;
        }

        if(temp+sum>sum) return temp+sum;

        return sum;
    }

    pair<ll,ll> give(vector<int>&nums, ll ind){
        ll n = nums.size();

        ll l = ind, r = -1, p = -1, q = n-1;
        bool flag = false;

        while(ind<n-1 && nums[ind]<=nums[ind+1]){
            if(nums[ind]==nums[ind+1]){
                l=ind+1;
            }
            ind++;
        }

        p = ind;
        while(ind<n-1 && nums[ind]>=nums[ind+1]){
            if(nums[ind]==nums[ind+1]) flag = true;
            ind++;
        }

        q = ind;
        while(ind<n-1 && nums[ind]<=nums[ind+1]){
            if(nums[ind]==nums[ind+1]){
                break;
            }
            ind++;
        }

        r=ind;

        if(p==-1 || q==n-1 || r==-1 || flag) return {LLONG_MIN,q};

        return {sum(nums,l,p,q,r),q};

        return {0,q};

    }

    ll maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        int ind = 0;

        while(nums[ind]>=nums[ind+1]) ind++;

        ll mx = LLONG_MIN;
        while(ind<n-1){
            auto [sm,q] = give(nums,ind);
            mx = max(mx,sm);
            ind = q;
        }

        return mx;
    }
};
