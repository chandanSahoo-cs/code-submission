#define ll long long

class Solution {
public:
    int minimumPairRemoval(vector<int>& num) {

        vector<ll>nums;

        for(auto ele:num){
            nums.push_back(ele);
        }

        int n = nums.size();

        unordered_map<ll,ll>next,prev;
        vector<bool>active(n,true);
        set<tuple<ll,ll,ll>>st;

        next[0]=1;
        prev[0]=-1;

        int faults = 0;
        int ops = 0;

        
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) faults++;

            next[i]=i+1;
            prev[i]=i-1;

            st.insert({nums[i]+nums[i-1],i-1,i}); 
        }

        while(faults>0){

            auto [sum,node1,node2] = *st.begin(); 
            st.erase({sum,node1,node2});

            if(!active[node1] || !active[node2] || nums[node1]+nums[node2]!=sum) continue;
            active[node2] = false;
            ops++;

            ll a = prev[node1]!=-1?nums[prev[node1]]:LLONG_MIN;
            ll b = nums[node1];
            ll c = nums[node2];
            ll d = next[node2]!=n?nums[next[node2]]:LLONG_MAX;

            if(b>c) faults--;

            if(a>b && b+c>=a) faults--;
            if(a<=b && b+c<a) faults++;
            if(d>=c && b+c>d) faults++;
            if(d<c && b+c<=d) faults--;

            nums[node1] = b+c;
            next[node1] = n;

            if(prev[node1]!=-1){
                // st.erase({a+b,prev[node1],node1});
                st.insert({a+b+c,prev[node1],node1});
            }

            if(next[node2]!=n){
                next[node1] = next[node2];
                prev[next[node2]] = node1;

                // st.erase({c+d,node2,next[node2]});
                st.insert({b+c+d,node1,next[node1]});
            }

        }

        return ops;
    }
};
