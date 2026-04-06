class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<char,int>,char>mp;

        // North
        mp[{'N',-1}] = 'E';
        mp[{'N',-2}] = 'W';

        // East
        mp[{'E',-1}] = 'S';
        mp[{'E',-2}] = 'N';

        // South
        mp[{'S',-1}] = 'W';
        mp[{'S',-2}] = 'E';

        // West
        mp[{'W',-1}] = 'N';
        mp[{'W',-2}] = 'S';

        set<pair<int,int>>st;

        for(auto &ele:obstacles){
            st.insert({ele[0],ele[1]});
        }

        char ini = 'N';
        int mx = 0;

        int x=0,y=0;

        for(auto c:commands){
            if(c>0){
                for(int i=1;i<=c;i++){
                    if(ini=='N'){
                        if(st.count({x,y+1})) break;
                        y+=1;
                    }else if(ini=='S'){
                        if(st.count({x,y-1})) break;
                        y-=1;
                    }else if(ini=='W'){
                        if(st.count({x-1,y})) break;
                        x-=1;
                    }else{
                        if(st.count({x+1,y})) break;
                        x+=1;
                    }
                }
                mx = max(mx,x*x+y*y);
            }else{
                ini = mp[{ini,c}];
            }
        }

        return mx;
    }
};
