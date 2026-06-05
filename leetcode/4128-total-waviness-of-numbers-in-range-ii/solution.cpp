#define ll long long

class Solution {
public:
    string s;
    int n;

    ll dpTotalNum[16][10][10];
    ll dpTotalWaviness[16][10][10];

    pair<ll,ll> rec(int curr, int prevPrev, int prev, bool isLimited, bool isLeadingZero){
        if(curr==n) return {1,0};

        if(!isLimited && !isLeadingZero && prevPrev >=0 && prev >=0){
            if(dpTotalNum[curr][prevPrev][prev]!=-1 && dpTotalWaviness[curr][prevPrev][prev]!=-1){
                return {dpTotalNum[curr][prevPrev][prev],dpTotalWaviness[curr][prevPrev][prev]};
            }
        }

        ll totNum = 0;
        ll totWaveScore = 0;

        int limitDigit = isLimited ?s[curr]-'0':9;

        for(int digit = 0; digit <= limitDigit; digit++){
            bool newIsLeadingZero = isLeadingZero && (digit==0);

            int newPrevPrev = prev;
            int newPrev = newIsLeadingZero ?-1:digit;

            auto [remainTotNumber,remainWaveScore] = rec(curr+1, newPrevPrev,newPrev,isLimited && (digit==limitDigit),newIsLeadingZero);

            if(!newIsLeadingZero && prevPrev >=0 && prev >=0){
                bool isPeak = (prevPrev< prev && prev>digit);
                bool isValley = (prevPrev>prev && prev<digit);

                if(isPeak || isValley){
                    totWaveScore +=remainTotNumber;
                }
            }

            totNum += remainTotNumber;
            totWaveScore += remainWaveScore;
        }

        if(!isLimited && !isLeadingZero && prevPrev >=0 && prev >=0){
            dpTotalNum[curr][prevPrev][prev] = totNum;
            dpTotalWaviness[curr][prevPrev][prev] = totWaveScore;
        }

        return { totNum,totWaveScore};
    }

    ll solve(ll num){
        if(num<100) return 0;

        s = to_string(num);
        n = s.size();

        memset(dpTotalNum,-1,sizeof(dpTotalNum));
        memset(dpTotalWaviness,-1,sizeof(dpTotalWaviness));
        auto [totNumbers, totWaveScore] = rec(0,-1,-1,true,true);

        return totWaveScore;
    }

    ll totalWaviness(ll num1, ll num2) {
        return solve(num2)-solve(num1-1);
    }
};
