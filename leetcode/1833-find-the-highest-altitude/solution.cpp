class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prev = 0;

        int mx = 0;

        for(auto ele:gain){
            int curr = prev+ele;
            mx = max(mx,curr);
            prev = curr;
        }

        return mx;
    }
};
