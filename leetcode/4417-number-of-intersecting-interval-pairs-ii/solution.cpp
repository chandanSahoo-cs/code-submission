#define ll long long

class Solution {
public:

    /*
    - get two copies of intervals [one,two]
    - sort one acc to r
    - sort two acc to l
    - iterate over the intervals [li,ri];
    - binary search for intervals in one for [li] to find r's which are smaller than li : nl
    - binary search for intervals in two for [ri] to find l's which are greater than ri : nr;
    - for that i number of intervals that intersect are n-nl-nr;
    */

    ll countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int>rights,lefts;

        for(auto ele:intervals){
            rights.push_back(ele[1]);
            lefts.push_back(ele[0]);
        }

        sort(rights.begin(),rights.end());
        sort(lefts.begin(),lefts.end());

        ll ans = 0;

        for(int i=0;i<n;i++){
            int l = intervals[i][0], r = intervals[i][1];

            ll nl = lower_bound(rights.begin(),rights.end(),l)-rights.begin();
            ll nr = lefts.end()-upper_bound(lefts.begin(),lefts.end(),r);

            ans+=n-nl-nr-1;
        }

        ans/=2;

        return ans;
    }
};

/*
l : 1 2 3
r : 2 3 4

*/
