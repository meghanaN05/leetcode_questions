class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();

        vector<int> pge(n), nge(n), pse(n), nse(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long sumMax = 0, sumMin = 0;

        for(int i = 0; i < n; i++) {
            long long maxCnt = (long long)(i - pge[i]) * (nge[i] - i);
            long long minCnt = (long long)(i - pse[i]) * (nse[i] - i);
            sumMax += maxCnt * arr[i];
            sumMin += minCnt * arr[i];
        }

        return sumMax - sumMin;
    }
};
