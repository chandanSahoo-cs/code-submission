class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<int>foo(n);
        iota(foo.begin(),foo.end(),0);

        sort(foo.begin(),foo.end(),[&](int i, int j){
            return position[i]<position[j];
        });

        int ans = 0;
        float refToTar = -1;

        for(int i=n-1;i>=0;i--){
            int ind = foo[i];
            float currToTar = (target-position[ind])/(float)(speed[ind]);

            if(currToTar>refToTar){
                refToTar = currToTar;
                ans++;
            }
        }

        return ans;
    }
};
