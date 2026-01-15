class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int contHBars=1,contVBars=1;
        int temp=1;

        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==hBars[i-1]+1) temp++;
            else temp=1;

            contHBars = max(temp,contHBars);
        }

        temp=1;

        for(int i=1;i<vBars.size();i++){
            if(vBars[i]==vBars[i-1]+1) temp++;
            else temp=1;

            contVBars = max(temp,contVBars);
        }

        contHBars++;
        contVBars++;

        int mn = min(contHBars,contVBars);

        return mn*mn;
    }
};
