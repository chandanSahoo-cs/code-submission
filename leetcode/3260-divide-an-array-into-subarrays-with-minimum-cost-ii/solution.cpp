class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int curr = 1;

        set<pair<int,int>,greater<>>mx;
        set<pair<int,int>>mn;


        int i = 1;

        while(i<=min(n-1,dist+1)){
            mx.insert({nums[i],i});

            while(mx.size()>k-1){
                mn.insert(*mx.begin());
                mx.erase(mx.begin());
            }

            i++;
        }

        set<pair<int,int>,greater<>>temp = mx;
        long long sum = 0;

        while(!temp.empty()){
            sum+=temp.begin()->first;
            temp.erase(temp.begin());
        }

        long long mnSum = sum;

        while(i<=n-1){
            if(mx.count({nums[curr],curr})){
                mx.erase({nums[curr],curr});
                sum-=nums[curr];
                curr++;
            }else if(mn.count({nums[curr],curr})){
                mn.erase({nums[curr],curr});
                curr++;
            }
            

            if(mx.size()<k-1 && mn.size()>0){
                mx.insert(*mn.begin());
                sum+=mn.begin()->first;
                mn.erase(mn.begin());
            }

            mx.insert({nums[i],i});
            sum+=nums[i];

            if(mx.size()>k-1){
                sum-=mx.begin()->first;
                mn.insert(*mx.begin());
                mx.erase(mx.begin());
            }

            mnSum = min(sum,mnSum);
            i++;
        }

        return nums[0]+mnSum;

    }
};
