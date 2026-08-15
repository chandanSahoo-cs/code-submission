class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = 0;
        int strt = 0;

        for(auto ele:requests){
            ans += abs(strt-ele);
            strt = ele;
        }

        return ans;
    }
};
