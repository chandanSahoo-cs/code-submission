class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(s.size()!=goal.size()) return false;

        string p = s+s;

        return p.find(goal)!=string::npos;
    }
};
