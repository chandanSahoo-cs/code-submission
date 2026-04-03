class Solution {
public:
    int calWalls(vector<int>&walls, int l, int r){
        if(l>r) return 0;

        auto right = upper_bound(walls.begin(),walls.end(),r);
        auto left = lower_bound(walls.begin(),walls.end(),l);

        return right-left;
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<int>foo(n);
        iota(foo.begin(),foo.end(),0);

        sort(foo.begin(),foo.end(),[&](int i, int j){
            return robots[i]<robots[j];
        });

        sort(walls.begin(),walls.end());

        pair<int,int>next = {0,0};
        pair<int,int>curr;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int leftL = robots[foo[i]]-distance[foo[i]];
                int rightR = robots[foo[i]]+distance[foo[i]];

                if(i>0){
                    int prevEnd = (j==0)?robots[foo[i-1]]+1:min(robots[foo[i-1]]+distance[foo[i-1]]+1,robots[foo[i]]);
                    leftL = max(leftL,prevEnd);
                }
                if(i<n-1){
                    rightR = min(rightR,robots[foo[i+1]]-1);
                }

                int left = calWalls(walls,leftL,robots[foo[i]])+next.first;
                int right = calWalls(walls,robots[foo[i]],rightR)+next.second;
                
                if(j==0){
                    curr.first = max(left,right);
                }else{
                    curr.second = max(left,right);
                }
            }

            next = curr;
        }

        return next.first;
    }
};
