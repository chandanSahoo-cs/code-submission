class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(),deadends.end());
        queue<string>q;

        if(st.count("0000")) return -1;
        if(target=="0000") return 0;

        q.push("0000");
        st.insert("0000");

        int level = 0;

        int rot[] = {-1,1};

        while(!q.empty()){
            int sz = q.size();
            level++;

            for(int i=0;i<sz;i++){
                string t = q.front();
                q.pop();

                for(int j=0;j<4;j++){
                    int ch = t[j]-'0';

                    for(int k=0;k<2;k++){
                        t[j]=((ch+rot[k]+10)%10)+'0';
                        if(t==target) return level;

                        if(!st.count(t)){
                            q.push(t);    
                            st.insert(t);
                        }
                    }

                    t[j]=ch+'0';
                }
            }
        }

        return -1;
    }
};
