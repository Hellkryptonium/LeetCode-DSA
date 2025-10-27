class SmallestInfiniteSet {
public:
    int curr;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> inHeap;
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if(!pq.empty()) {
            int smallest = pq.top();
            pq.pop();
            inHeap.erase(smallest);
            return smallest;
        }
        return curr++;
    }
    
    void addBack(int num) {
        if(num < curr && inHeap.find(num) == inHeap.end()) {
            pq.push(num);
            inHeap.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */