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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while(head != nullptr) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow);

        ListNode* firstHalf = head;
        ListNode* tempSecond = secondHalf;
        bool isPal = true;

        while(tempSecond != nullptr) {
            if(firstHalf->val != tempSecond->val) {
                isPal = false;
                break;
            }
            firstHalf = firstHalf->next;
            tempSecond = tempSecond->next;
        }

        return isPal;
    }
};