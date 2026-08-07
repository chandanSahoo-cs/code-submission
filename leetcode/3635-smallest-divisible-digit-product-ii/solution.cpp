#define ll long long

class Solution {
public:
    string smallestNumber(string nums, ll t) {
        int n = nums.size();
        int divs[] = {2,3,5,7};


        ll nt = t;
        for(int i=0;i<4;i++){
            while(nt%divs[i]==0){
                nt/=divs[i];
            }
        }

        if(nt>1) return "-1";

        vector<ll>rem(n+1);
        rem[0] = t;

        int pos = n-1;

        for(int i=0;i<n;i++){
            if(nums[i]=='0'){
                pos = i; // can start chaning the number from here because it is zero which we don't want
                break;
            }
            rem[i+1] = rem[i]/__gcd((ll)(nums[i]-'0'),rem[i]);
        }

        if(rem[n]==1){
            return nums;
        }


        for(int i=pos;i>=0;i--){
            ll dig = (nums[i]-'0');
            ll org = rem[i];
            dig++;

            while(dig<10){
                ll curr = org/__gcd(org,dig);
                ll k = 9;

                string temp = "";

                for(ll j=n-1;j>i;j--){
                    while(__gcd(curr,k)!=k) k--;
                    temp+=k+'0';
                    curr/=k;
                }

                if(curr==1){
                    reverse(temp.begin(),temp.end());
                    for(ll j=n-1;j>i;j--){
                        nums[j]=temp.back();
                        temp.pop_back();
                    }

                    nums[i] = dig+'0';

                    return nums;
                }

                dig++;
            }
        }

        string ans = "";
        ll k = 9;

        while(t>1){
            while(__gcd(t,k)!=k) k--;
            ans+=k+'0';
            t/=k;
        }

        while(ans.size()<n+1){
            ans+='1';
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
/*
50*50*10
*/

/*
if it has a prime factor > 9 then it is impossible to create a ans string
else it is always possible to create a ans string
*/
