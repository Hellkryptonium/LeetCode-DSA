/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        Node* newHead = new Node(head->val);
        Node* newTemp = newHead;
        Node* oldTemp = head->next;

        unordered_map<Node*, Node*> m;
        m[head] = newHead;

        //copy
        while(oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp -> val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;
            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;
        }
        //copy of random pointers
        oldTemp = head; newTemp = newHead;
        while(oldTemp != NULL) {
            if(oldTemp -> random != NULL) {
                newTemp -> random = m[oldTemp->random];
            } else {
                newTemp -> random = NULL;
            }
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};