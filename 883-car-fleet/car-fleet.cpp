class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        int n = speed.size();
        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.rbegin(), cars.rend());
        int fleets = 0;
        double prevTime = 0.0;
        for (auto& car : cars) {
            double time = car.second;
            if (time > prevTime) {
                fleets++;
                prevTime = time;
            }
        }
        return fleets;
    }
};