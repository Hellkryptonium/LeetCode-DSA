/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vals;

        ListNode* curr = head;
        while(curr) {
            vals.push_back(curr->val);
            curr=curr->next;
        }

        int l=0, r=vals.size()-1;
        int maxSum = 0;

        while(l < r) {
            maxSum = max(maxSum, vals[l] + vals[r]);
            l++;
            r--;
        }
        return maxSum;
    }
};