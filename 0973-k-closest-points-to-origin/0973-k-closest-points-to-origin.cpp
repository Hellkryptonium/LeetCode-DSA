class Solution {
class Car {
public:
    int idx;
    int distSq;

    Car(int idx, int distSq) {
        this->idx = idx;
        this->distSq = distSq;
    }

    bool operator<(const Car& obj) const {
        return this->distSq > obj.distSq;
    }
};
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<Car> cars;

        for(int i=0; i<points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            cars.push_back(Car(i, dist));
        }

        priority_queue<Car> pq(cars.begin(), cars.end());
        vector<vector<int>> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(points[pq.top().idx]);
            pq.pop();
        }

        return ans;

    }
};