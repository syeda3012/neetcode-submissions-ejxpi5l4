class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>>cars;
        for(int i = 0; i < n; i++){
            double time = (double)((target - position[i])/ speed[i]);
            cars.push_back({position[i], time});

        }
        int fleets = 0;
        int curr = 0;
        sort(cars.begin(), cars.end());
        for(int i = n-1; i >= 0; i--){
            if(cars[i].second > curr){
                fleets++;
                curr = cars[i].second;
            }
        }
        return fleets;
    }
};
