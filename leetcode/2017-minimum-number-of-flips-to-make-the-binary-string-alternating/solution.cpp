class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int odd0=0,odd1=0,even0=0,even1=0;

        for(int i=0;i<n;i++){
            if(i%2){
                if(s[i]=='0') odd0++;
                else odd1++;
            }else{
                if(s[i]=='0') even0++;
                else even1++;
            }
        }

        int ans = min(odd1+even0,odd0+even1);
        if(n%2){
            for(int i=0;i<n-1;i++){
                swap(odd0,even0);
                swap(odd1,even1);

                if(s[i]=='0'){
                    odd0--;
                    even0++;
                }else{
                    odd1--;
                    even1++;
                }

                ans = min(ans,min(odd1+even0,odd0+even1));
            }
        }

        return ans;
    }
};
