class EventManager {
public:
    unordered_map<int,int>mp;
    struct cmp {
        bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) const {
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first > p2.first;        
        }
    };

    set<pair<int,int>, cmp> st;
    
    EventManager(vector<vector<int>>& events) {
        for(auto &ele:events){
            mp[ele[0]] = ele[1];
            st.insert({ele[1],ele[0]});
        }    
    }
    
    void updatePriority(int eventId, int newPriority) {

        st.erase({mp[eventId],eventId});
        
        st.insert({newPriority,eventId});
        mp[eventId] = newPriority;

        return;
    }
    
    int pollHighest() {

        if(!st.size()) return -1;
        
        auto [p,e] = *st.begin();
        st.erase(*st.begin());
        
        return e;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
