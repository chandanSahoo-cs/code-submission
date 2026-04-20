class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int mx = 0;

        int i = 0, j = n-1;

        while(i<j && colors[i]==colors[j]){
            i++;
        }

        mx = max(abs(i-j),mx);

        i=0,j=n-1;

        while(i<j && colors[i]==colors[j]){
            j--;
        }

        mx = max(abs(i-j),mx);

        return mx;
    }
};
