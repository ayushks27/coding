class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        int ans = 0;
        double prev = 0.0;

        for (auto car : cars) {
            double time = (double)(target - car.first) / car.second;

            if (time > prev) {
                ans++;
                prev = time;
            }
        }

        return ans;
    }
};