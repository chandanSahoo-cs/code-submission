class Solution {
public:
    #define ll long long

    ll firstDig(ll num){
        ll dig=-1;

        while(num){
            dig = num%10;
            num/=10;
        }

        return dig;
    }
    
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();

        int cnt = 0;
        
        for(int i=0;i<n;i++){
            ll sum = 0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                int last = sum%10;
                ll first = firstDig(sum);
                if(last==x && first==x) cnt++;
            }
        }

        return cnt;
    }
};
