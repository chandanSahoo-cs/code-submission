#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_multiset =
    tree<pair<T, int>,
         null_type,
         less<pair<T, int>>,
         rb_tree_tag,
         tree_order_statistics_node_update>;

class Solution {
public:
    int grtCnt(ordered_multiset<int>&st,int trg){
        int cnt = st.size()-st.order_of_key({trg,INT_MAX});
        return cnt;
    }

    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        vector<int>a,b;
        ordered_multiset<int>sta,stb;

        a.push_back(nums[i]);
        sta.insert({nums[i],i++});

        b.push_back(nums[i]);
        stb.insert({nums[i],i++});

        while(i<n){
            int cnta = grtCnt(sta,nums[i]);
            int cntb = grtCnt(stb,nums[i]);

            if(cnta>cntb){
                a.push_back(nums[i]);
                sta.insert({nums[i],i});
            }else if(cnta<cntb){
                b.push_back(nums[i]);
                stb.insert({nums[i],i});
            }else if(a.size()<b.size()){
                a.push_back(nums[i]);
                sta.insert({nums[i],i});
            }else if(a.size()>b.size()){
                b.push_back(nums[i]);
                stb.insert({nums[i],i});
            }else{
                a.push_back(nums[i]);
                sta.insert({nums[i],i});
            }

            i++;
        }

        vector<int>ans(a.begin(),a.end());
        ans.insert(ans.end(),b.begin(),b.end());

        return ans;
    }
};
