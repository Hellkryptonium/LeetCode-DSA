class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;

        int result = 0;
        for(int i=0; i<n; i++) {
            unordered_map<long long, int> slopeCount;
            int localMax = 0;
            for(int j=i+1; j<n; j++) {
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];

                if(dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                if(dx == 0) {
                    dy = 1;
                } else if(dy == 0) {
                    dx = 1;
                } else {
                    int g = std::gcd(abs(dy), abs(dx));
                    dy /= g;
                    dx /= g;
                }

                long long key = ((long long)dy << 32) ^ (long long)dx;
                slopeCount[key]++;
                localMax = max(localMax, slopeCount[key]);
            }

            result = max(result, localMax + 1);
        }
        return result;
    }
};