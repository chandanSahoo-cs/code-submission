class Solution {
public:

    int mh(int x1, int y1, int x2, int y2){
        return abs(x1-x2)+abs(y1-y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        unordered_map<int,pair<int,int>>mp;
        mp[0] = {-1,-1};

        int x = 0, y = 0;

        for(char c='A';c<='Z';c++){
            mp[c-'A'+1] = {x,y};
            x++;
            if(x==6){
                x=0;
                y++;
            }
        }

        vector<vector<int>>curr(27,vector<int>(27));
        vector<vector<int>>next(27,vector<int>(27));

        for(int i=n-1;i>=0;i--){
            for(int frst=26;frst>=0;frst--){
                for(int scnd=26;scnd>=0;scnd--){
                    int c = word[i]-'A'+1;

                    auto [fx,fy] = mp[frst];
                    auto [sx,sy] = mp[scnd];
                    auto [cx,cy] = mp[c];

                    curr[frst][scnd] = min((frst==0?0:mh(fx,fy,cx,cy))+next[c][scnd],
                                                (scnd==0?0:mh(sx,sy,cx,cy))+next[frst][c]);
                }
                next = curr;
            }
        }

        return next[0][0];
    }
};
