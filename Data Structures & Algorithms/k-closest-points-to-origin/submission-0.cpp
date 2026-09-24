class Solution {
public:
   int getDist(const vector<int>&point){
    return point[0]*point[0]+point[1]*point[1];
}
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

    priority_queue<pair<int, vector<int>>> pq;
    for(auto itt : points){
        int dist=getDist(itt);
        pq.push({dist,itt});
        if(pq.size()>k ){
            pq.pop();
        }

    }
    vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
}
};