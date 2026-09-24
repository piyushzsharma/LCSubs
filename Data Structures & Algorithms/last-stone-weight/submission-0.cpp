class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
       
        while(pq.size()>1){
            int one=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            if(one-second) pq.push(one-second);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};