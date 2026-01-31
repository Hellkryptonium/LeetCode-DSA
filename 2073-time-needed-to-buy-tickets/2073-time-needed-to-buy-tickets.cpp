class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        if(tickets.empty()) {
            return -1;
        }
        int n = tickets.size();
        queue<int> q;
        int time = 0;

        for(int i=0; i<n; i++) {
            q.push(i);
        }

        while(tickets[k] > 0) {
            int index = q.front();
            q.pop();

            tickets[index]--;
            time++;

            if(tickets[index] > 0) q.push(index);
        }
        
        return time;
    }
};