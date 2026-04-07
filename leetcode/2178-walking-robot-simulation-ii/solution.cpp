class Robot {
    int w, h;
    int x,y;
    char dir;
    unordered_map<char,char>mp;
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        x = y = 0;
        dir = 'E';

        mp['E'] = 'N';
        mp['S'] = 'E';
        mp['W'] = 'S';
        mp['N'] = 'W';
    }
    
    void step(int num) {
        
        int total = 2*(w+h)-4;
        int curr = num%total;

        if(curr==0){
            if(x==0 && y==0){
                dir='S';
            }
        }

        while(curr){
            if(dir=='E'){
                int move = min(curr,w-1-x);
                x+=move;
                curr-=move;
            }else if(dir=='S'){
                int move = min(curr,y);
                y-=move;
                curr-=move;
            }else if(dir=='W'){
                int move = min(curr,x);
                x-=move;
                curr-=move;
            }else {
                int move = min(curr,h-1-y);
                y+=move;
                curr-=move;
            }

            if(curr>0) dir = mp[dir];
        }

        return;
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dir=='N') return "North";
        else if(dir=='E') return "East";
        else if(dir=='S') return "South";
        
        return "West";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
