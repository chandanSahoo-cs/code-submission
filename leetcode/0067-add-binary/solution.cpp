class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";

        int i=a.size()-1, j=b.size()-1;
        int carry = 0;

        while(i>=0 || j>=0){
            int curr = (i>=0?a[i]-'0':0)+(j>=0?b[j]-'0':0)+carry;

            if(curr%2){
                ans+='1';
            }else ans+='0';

            if(curr>1){
                carry=1;
            }else carry=0;

            i--;
            j--;
        }

        if(carry){
            ans+=carry+'0';
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
