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
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* secondHalf = reverse(slow);
        ListNode* firstHalf = head;
        ListNode* tempSecondHalf = secondHalf;

        while(tempSecondHalf) {
            if(tempSecondHalf->val != firstHalf->val) {
                return false;
            }
            tempSecondHalf=tempSecondHalf->next;
            firstHalf = firstHalf->next;
        }

        return true;

    }
};