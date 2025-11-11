class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> valid(bank.begin(), bank.end());
        if(!valid.count(endGene)) return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        vector<char> choices = {'A', 'C', 'G', 'T'};

        while(!q.empty()) {
            auto [gene, steps] = q.front();
            q.pop();

            if(gene == endGene) return steps;

            for(int i=0; i<8; i++) {
                char original = gene[i];

                for(char ch : choices) {
                    if(ch == original) continue;
                    gene[i] = ch;
                    
                    if(valid.count(gene)) {
                        q.push({gene, steps + 1});
                        valid.erase(gene);
                    }
                }
                gene[i] = original;
            }
        }
        return -1;
    }
};