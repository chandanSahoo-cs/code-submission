class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int>foo(n,0);
        iota(foo.begin(),foo.end(),0);

        sort(foo.begin(),foo.end(),[&](int i, int j){
            return positions[i]<positions[j];
        });

        stack<pair<int,int>>st;

        for(auto i:foo){
            int val = healths[i], ind = i;
            char dir = directions[i];

            bool flag=true;

            while(!st.empty() && directions[st.top().first]=='R' && dir=='L'){
                auto [sind,sval] = st.top();
                st.pop();
                if(val>sval){
                    val--;
                }else{
                    flag=false;
                    if(val!=sval){
                        st.push({sind,sval-1});
                    }
                    break;
                }
            }

            if(flag) st.push({ind,val});
        }

        vector<pair<int,int>>store;

        while(!st.empty()){
            store.push_back(st.top());
            st.pop();
        }

        sort(store.begin(),store.end(),[&](pair<int,int>p1,pair<int,int>p2){
            return p1.first<p2.first;
        });

        vector<int>ans;

        for(auto &[ind,val]:store){
            ans.push_back(val);
        }

        return ans;
    }
};
