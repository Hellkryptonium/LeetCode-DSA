class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAltitude = 0;
        int maxAltitude = 0;

        for(int g : gain) {
            currAltitude += g;
            if(currAltitude > maxAltitude) {
                maxAltitude = currAltitude;
            }
        }
        return maxAltitude;
    }
};