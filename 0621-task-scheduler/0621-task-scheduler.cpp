class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         unordered_map<char, int> freq;
       for (char task : tasks) {
        freq[task]++;
    }
    int maxi = 0;
    for (auto &p : freq) {
        maxi = max(maxi, p.second);
    }
    int num_max = 0;
    for (auto &p : freq) {
        if (p.second == maxi) num_max++;
    }
    int intervals = (maxi- 1) * (n + 1) + num_max;
    return max((int)tasks.size(), intervals);
    }
};