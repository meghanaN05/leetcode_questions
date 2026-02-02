class SmallestInfiniteSet {
public:
    int curr;
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> st;
    SmallestInfiniteSet() {
        curr = 1;
    }
    int popSmallest() {
        int ans;
        if (!pq.empty()) {
            ans = pq.top();
            pq.pop();
            st.erase(ans);  
        } else {
            ans = curr;
            curr++;
        }
        return ans;
    }
    void addBack(int num) {
        if (num < curr && st.find(num) == st.end()) {
            pq.push(num);
            st.insert(num);
        }
    }
};




/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */