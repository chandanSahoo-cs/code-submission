#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<>>pq(nums.begin(),nums.end());

        int cnt = 0;

        while(pq.size()>1 && pq.top()<k){
            ll frst = pq.top(); pq.pop();
            ll scnd = pq.top(); pq.pop();

            pq.push(frst*2+scnd);
            cnt++;
        }

        return cnt;
    }
};
