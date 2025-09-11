class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        for(int i = 0; i < n;) {
            int start = i;
            // Find the end of the current word
            while(i < n && title[i] != ' ') i++;
            int end = i - 1;
            int len = end - start + 1;

            if(len <= 2) {
                // Make the whole word lowercase
                for(int j = start; j <= end; j++) {
                    if(title[j] >= 'A' && title[j] <= 'Z') {
                        title[j] = title[j] - 'A' + 'a';
                    }
                }
            } else {
                // Capitalize first letter
                if(title[start] >= 'a' && title[start] <= 'z') {
                    title[start] = title[start] - 'a' + 'A';
                }
                // Lowercase remaining letters
                for(int j = start + 1; j <= end; j++) {
                    if(title[j] >= 'A' && title[j] <= 'Z') {
                        title[j] = title[j] - 'A' + 'a';
                    }
                }
            }
            i++; // Skip the space
        }
        return title;
    }
};
