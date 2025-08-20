class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = candies[0];
        for(int i=0; i<candies.size(); i++) {
            if(candies[i] > maxCandies) {
                maxCandies = candies[i];
            }
        }
        vector<bool> result;

        for(int candy : candies) {
            if(candy + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};