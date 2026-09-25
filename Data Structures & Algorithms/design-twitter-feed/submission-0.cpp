class Twitter {
public:
    vector<unordered_set<int>> following;
    vector<vector<pair<int,int>>> posts;
    int timestamp=0;

    Twitter():following(501),posts(501){
        
    }
    
    void postTweet(int userId, int tweetId) {
        following[userId].insert(userId);
        posts[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        //now need pq and vector to return
        // pq={timestamp,{userid,index}}
        vector<int> feed;
        priority_queue<pair<int,pair<int,int>>> pq;

        for(auto it:following[userId]){
        if(!posts[it].empty()){
        int index = posts[it].size() - 1;

        pq.push({
            posts[it][index].first,
            {it, index}
        });
         }  
        }
 
        while(!pq.empty()&& feed.size()<10){
            //auto [time, takenuserid, index] = pq.top();
            auto [time, pairval] = pq.top();
            pq.pop();
            int takenuserid=pairval.first;
            int index=pairval.second;
            int newindex=index-1;
           // int takenuserid=top.second.first;
           // int newindex=top.second.second-1;
            feed.push_back(posts[takenuserid][index].second);
            if(newindex>=0)pq.push({posts[takenuserid][newindex].first,{takenuserid,newindex}});
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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