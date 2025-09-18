class TaskManager {
    typedef pair<int, int> P;
    priority_queue<P> q;
    unordered_map<int, int> mp1, mp2;

public:
    TaskManager(vector<vector<int>>& v) {
        for (auto& x : v) {
            add(x[0], x[1], x[2]);
        }
    }

    void add(int u, int t, int p) {
        q.push({p, t});
        mp1[t] = p;
        mp2[t] = u;
    }

    void edit(int t, int p) {
        q.push({p, t});
        mp1[t] = p;
    }

    void rmv(int t) {
        mp1[t] = -1;
    }

    int execTop() {
        while (!q.empty()) {
            auto [p, t] = q.top();
            q.pop();
            if (p == mp1[t]) {
                mp1[t] = -1;
                return mp2[t];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */