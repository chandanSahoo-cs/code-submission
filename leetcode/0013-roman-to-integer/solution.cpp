class Solution {
public:

    int romanToInt(string s) {
        map<char,int>mp;
        mp['M']=1000;
        mp['D']=500;
        mp['C']=100;
        mp['L']=50;
        mp['X']=10;
        mp['V']=5;
        mp['I']=1;

        int cnt=0;

        for(int i=s.size()-1;i>=0;i--){
            if(i==s.size()-1 || mp[s[i]]>=mp[s[i+1]]){
                cnt+=mp[s[i]];
            }else{
                cnt-=mp[s[i]];
            }

            cout<<cnt<<"\n";
        }

        return cnt;
    }
};
