class Solution {
public:
    int len = 0;

    void populate(unordered_set<int>&st, int i){
        while(i){
            st.insert(i);
            i/=10;
        }

        return;
    }

    void check(unordered_set<int>&st,int i){
        while(i){
            if(st.count(i)){
                len = max(len,(int)log10(i)+1);
            }
            i/=10;
        }

        return;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();

        unordered_set<int>st;

        for(int i=0;i<n;i++){
            populate(st,arr1[i]);
        }

        for(int i=0;i<m;i++){
            check(st,arr2[i]);
        }

        return len;
    }
};
