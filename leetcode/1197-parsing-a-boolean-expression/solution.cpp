class Solution {
public:
bool parseBoolExpr(string s) {
    stack<char>st;
    string exp = s;
    int n = exp.size();
    int i=0;

    while(i<n){
        if(exp[i]!=')' && exp[i]!=','){
            st.push(exp[i]);
        }else if(exp[i]==')'){
            bool falsy = false;
            bool truthy =false;
            char val = 't';
            while(st.top()!='('){
                if(st.top()=='f'){
                    falsy = true;
                    val = 'f';
                }
                if(st.top()=='t') {
                    truthy = true;
                    val = 't';
                }


                st.pop();
            }
            st.pop();

            if(st.top()=='!'){
                if(truthy){
                    val='f';
                }
                if(falsy){
                    val = 't';
                }
            }

            if(st.top()=='&'){
                if(falsy){
                    val='f';
                }else val = 't';
            }

            if(st.top()=='|'){
                if(!truthy){
                    val='f';
                }else val = 't';
            }
            st.pop();
            st.push(val);
        }
        i++;
    }

    return st.top()=='t';
}

};
