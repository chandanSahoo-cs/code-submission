class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        int level = 0;

        set<vector<int>>st(points.begin(),points.end());

        while(true){
            int n = points.size();

            for(auto ele:points){
                if(ele==target) return level;
            }

            vector<vector<int>>temp;

            for(int i=0;i<n;i++){
                int x1 = points[i][0], y1 = points[i][1], z1 = points[i][2];
                for(int j=i+1;j<n;j++){
                    int x2 = points[j][0], y2 = points[j][1], z2 = points[j][2];

                    int a = (x1+x2)/2, b = (y1+y2)/2, c = (z1+z2)/2;

                    if(st.find({a,b,c})==st.end()){
                        temp.push_back({a,b,c});
                        st.insert({a,b,c});
                    }
                }
            }

            if(temp.size()==0) break;

            for(auto &ele:temp){
                points.push_back(ele);
            }

            level++;
        }

        return -1;
    }
};

