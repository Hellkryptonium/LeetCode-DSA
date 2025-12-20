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
    bool isPalindrome(ListNode* head) {
        vector<int> front;
        ListNode* curr = head;
        while(curr) {
            front.push_back(curr->val);
            curr=curr->next;
        }

        vector<int> back(front.begin(), front.end());
        reverse(front.begin(), front.end());

        if(front == back) {
            return true;
        }

        return false;
    }
};