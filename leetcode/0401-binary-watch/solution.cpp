class Solution {
public:
    int bitCnt(int num){
        int cnt=0;

        while(num){
            cnt+=num%2;
            num/=2;
        }

        return cnt;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        
        vector<string>ans;

        for(int i=0;i<=11;i++){
            int bits = bitCnt(i);
            for(int j=0;j<=59;j++){

                if(bits+bitCnt(j)==turnedOn){
                    string s = "";
                    s+=to_string(i);

                    s+=':';

                    if(j<10) s+='0';
                    s+=to_string(j);

                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};
