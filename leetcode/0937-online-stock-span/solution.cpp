class StockSpanner {
public:
    StockSpanner() {
        
    }

    stack<pair<int,int>>st;
    
    int next(int price) {
        int cnt=0;
        while(!st.empty() && st.top().first<=price){
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price,cnt+1});

        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
