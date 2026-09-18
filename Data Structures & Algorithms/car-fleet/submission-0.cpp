class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        double fleettime=0;
        int fleets=0;
        int n=position.size();
        vector<pair<int,double>> cars;
        for(int i=0;i<n;i++){
            cars.push_back({position[i],(double)(target-position[i])/speed[i]});
        }
        sort(cars.begin(),cars.end());
        for(int i=n-1;i>=0;i--){
            double time=cars[i].second;
            if(time>fleettime) {
                fleets++;
                fleettime=time;
            }
        }
        return fleets;
    }
};