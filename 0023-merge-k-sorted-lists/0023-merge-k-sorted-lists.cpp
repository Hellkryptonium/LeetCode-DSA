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
    ListNode* merge(ListNode* a, ListNode* b) {
        if(!a) return b;
        if(!b) return a;

        if(a->val < b->val) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }

    ListNode* mergeRange(vector<ListNode*>& lists, int l, int r) {
        if(l > r) return nullptr;
        if(l == r) return lists[l];

        int mid = (l+r)/2;

        ListNode* left = mergeRange(lists, l, mid);
        ListNode* right = mergeRange(lists, mid+1, r);

        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return mergeRange(lists, 0, lists.size()-1);
    }
};