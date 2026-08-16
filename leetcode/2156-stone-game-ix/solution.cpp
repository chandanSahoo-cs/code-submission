class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for(auto ele:stones){
            cnt0+=(ele%3==0);
            cnt1+=(ele%3==1);
            cnt2+=(ele%3==2);
        }

        if((cnt2-cnt1>2 || cnt1-cnt2>2) && cnt0&1) return true;
        return cnt1>=1 && cnt2>=1 && !(cnt0&1);
    }
};
