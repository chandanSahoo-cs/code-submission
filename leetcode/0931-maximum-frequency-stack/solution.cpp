class FreqStack {
public:
    int mx;
    unordered_map<int,vector<int>>mp;
    unordered_map<int,int>freq;

    FreqStack() {
        mx=0;    
    }
    
    void push(int val) {
        freq[val]++;
        mx = max(mx,freq[val]);

        mp[freq[val]].push_back(val);
    }
    
    int pop() {
        int ele = mp[mx].back();
        mp[mx].pop_back();

        freq[ele]--;
        if(mp[mx].size()==0) mx--;

        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
