class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;

        int total = accumulate(nums.begin(),nums.end(),0);

        vector<vector<int>>left(n+1);
        vector<vector<int>>right(n+1);

        // left part
        for(int mask=0;mask<(1<<m);mask++){
            int sum = 0;
            int cnt = 0;

            for(int i=0;i<m;i++){
                if((mask>>i)&1){
                    sum+=nums[i];
                    cnt++;
                }
            }

            left[cnt].push_back(sum);
        }


        // right part
        for(int mask=0;mask<(1<<m);mask++){
            int sum = 0;
            int cnt = 0;

            for(int i=m;i<n;i++){
                if((mask>>(i-m))&1){
                    sum+=nums[i];
                    cnt++;
                }
            }

            right[cnt].push_back(sum);
        }

        for(int i=0;i<m;i++){
            sort(right[i].begin(),right[i].end());
        }

        int mn = INT_MAX;

        for(int i=0;i<=m;i++){
            for(auto sum:left[i]){

                int trg = total/2-sum;

                auto itr = upper_bound(right[m-i].begin(),right[m-i].end(),trg);
                if(itr==right[m-i].begin()) continue;
                itr--;

                mn = min(mn,abs(total-2*(sum+(*itr))));
            }
        }

        return mn;
    }
};
