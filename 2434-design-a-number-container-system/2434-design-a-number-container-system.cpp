class NumberContainers {
public:
    std::unordered_map<int, int> m;
    std::unordered_map<int, std::set<int>> s;

    NumberContainers() {}

    void change(int index, int number) {
        if (m.find(index) != m.end()) {
            int prevNumber = m[index];  
            s[prevNumber].erase(index);
            if (s[prevNumber].empty()) { 
                s.erase(prevNumber); 
            }
        }
        m[index] = number;
        s[number].insert(index);
    }

    int find(int number) {
        if (s[number].empty()) {
            return -1;
        } else {
            return *(s[number].begin()); 
        }
    }
};


/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */