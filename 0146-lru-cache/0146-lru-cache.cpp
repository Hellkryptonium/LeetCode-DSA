using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addNode(node);
    }

    Node* popTail() {
        Node* lru = tail->prev;
        removeNode(lru);
        return lru;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* node = mp[key];
        moveToFront(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            moveToFront(node);
            return;
        }
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        addNode(newNode);
        if(mp.size() > cap) {
            Node* lru = popTail();
            mp.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */