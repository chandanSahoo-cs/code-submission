class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>follows;
    int time;

    Twitter() {
       time=0;     
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // const cmp = [](pair<int,int>p1, pair<int,int>p2){
        //     return p1.first<p2.first;
        // }

        priority_queue<pair<int,int>>pq;
        
        follows[userId].insert(userId);

        // for(auto ele:tweets[userId]){
        //     cout<<"Time: "<<ele.first<<" Id: "<<ele.second<<"\n";
        // }

        for(auto user:follows[userId]){
            for(auto ele:tweets[user]){
                pq.push({ele.first, ele.second});
                // if(pq.size()==10) break;
            }
        }
        vector<int>ans;
        while(!pq.empty() && ans.size()<10){
            ans.push_back(pq.top().second);
            pq.pop();
        }    

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].extract(followeeId);
        return;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
