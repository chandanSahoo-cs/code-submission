class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;

        for(int i=1;i<=9;i++){
            q.push(i);
        }

        vector<int>ans;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            int d = u%10;

            if(u>=low && u<=high){
                ans.push_back(u);
            }
            if(d==9) continue;
            q.push(u*10+d+1);
        }

        return ans;
    }
};
