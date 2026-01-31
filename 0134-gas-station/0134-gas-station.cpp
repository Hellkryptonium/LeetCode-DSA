
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if(totalGas < totalCost) return -1;

        int strindex = 0;
        int currGas = 0;

        for(int i=0; i<n; i++) {
            currGas += gas[i] - cost[i];
            if(currGas < 0) {
                strindex = i+1;
                currGas = 0;
            }
        }

        return strindex;
    }
};