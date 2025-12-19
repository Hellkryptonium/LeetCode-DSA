class Solution {
public:
    int getSize(ListNode* head) {
        int sz = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            sz++;
        }
        return sz;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);

        // If the head is the node to remove
        if (n == size) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* prev = head;
        for (int i = 1; i < size - n; i++) {
            prev = prev->next;
        }

        ListNode* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;

        return head;
    }
};
