class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {

        int score = 0, counter = 0;

        for(auto ele:events){
            if(counter==10) break;
            if(ele.size()==1 && ele[0]!='W'){
                score+=ele[0]-'0';
            }else{
                if(ele=="W") counter++;
                else if(ele=="WD" || ele=="NB") score++;
            }
        }

        return {score,counter};
    }
};
