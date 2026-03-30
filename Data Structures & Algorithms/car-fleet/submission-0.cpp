class Solution {
    static bool cmp(pair<int, double> a, pair<int, double> b){
        return a.first > b.first;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for(int i = 0; i < n; i++){
            double time = double(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), cmp);

        int fleets = 0;
        double maxtime = 0;

        for(int i = 0; i < n; i++){
            if(cars[i].second > maxtime){
                fleets++;
                maxtime = cars[i].second;
            }
        }
        return fleets;
    }
};