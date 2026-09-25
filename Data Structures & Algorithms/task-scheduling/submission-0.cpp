class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        int size=tasks.size();
        vector<int> mp(26);
        for(char ch:tasks){
            mp[ch-'A']++;
        }

        for(int i=0;i<26;i++){
            if(mp[i]>0) pq.push(mp[i]);
        }

        int ans=0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int top=pq.top();
                    pq.pop();
                    top--;
                    temp.push_back(top);
                }
            }

            for(auto it:temp){

             if(it)pq.push(it);
            }
            if(pq.empty()){
                ans+=temp.size();
            }
            else ans+=n+1;
        }

        
        return ans;


    }
};