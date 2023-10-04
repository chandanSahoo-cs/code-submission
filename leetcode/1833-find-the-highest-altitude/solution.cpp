class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        for(int i=1;i<gain.size();i++){
            gain[i]+=gain[i-1];
        }
        auto maxAlt=max_element(gain.begin(),gain.end());
        if(*maxAlt<0){
            return 0;
        }
        return *maxAlt;
    }
};
