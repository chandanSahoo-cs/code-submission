class Solution {
public:

    int minAddToMakeValid(string s) {
        int open = 0, more = 0;

        for(auto c:s){
            if(c=='(') open++;
            else{
                if(open) open--;
                else more++;
            }
        }

        return open+more;
    }
};
