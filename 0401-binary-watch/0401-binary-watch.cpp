class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while(n > 0) {
            count += (n % 2);
            n /= 2;
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for(int hour = 0; hour < 12; hour++) {
            for(int minutes = 0; minutes < 60; minutes++) {
                if(countBits(hour) + countBits(minutes) == turnedOn) {
                    string time = to_string(hour) + ":";

                    if(minutes < 10) {
                        time += "0";
                    }

                    time += to_string(minutes);

                    result.push_back(time);
                }
            }
        }
        return result;
    }
};