class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        long long hold = -prices[0];
        long long cash = 0;

        for(int i=1; i<prices.size(); i++) {
            cash = max(cash, hold+prices[i]-fee);
            hold = max(hold, cash-prices[i]);
        }

        return (int)cash;
    }
};