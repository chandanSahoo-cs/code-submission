class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int minValue=INT_MAX;
        int maxValue=INT_MIN;
        for(int i=0;i<logs.size();i++){
            minValue=min(minValue,logs[i][0]);
            maxValue=max(maxValue,logs[i][1]);
        }
        vector<int>freq(maxValue-minValue+1,0);
        for(int i=0;i<logs.size();i++){
            freq[logs[i][0]%minValue]++;
            freq[logs[i][1]%minValue]--;
        }
        int maxYear=0;
        for(int i=1;i<freq.size();i++){
            freq[i]+=freq[i-1];
            if(freq[i]>freq[maxYear]) maxYear=i;
        }
        return maxYear+minValue;
        
    }
};
