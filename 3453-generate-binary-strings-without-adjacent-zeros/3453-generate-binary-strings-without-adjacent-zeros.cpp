

class Solution {
public:
    vector<string> ans;

    // Member function to generate valid strings
    vector<string> validStrings(int n) {
        ans.clear(); // Clear the answer vector for fresh results
        func(n, ""); // Start the recursive function
        return ans;  // Return the result
    }

private:
    // Recursive function to generate valid strings
    void func(int n, string s) {
        if (n == 0) {
            ans.push_back(s); // Add the valid string to the answer vector
            return;
        }
        if (s.empty() || s.back() == '1') {
            func(n - 1, s + '0');
            func(n - 1, s + '1');
        } else {
            func(n - 1, s + '1');
        }
    }
};
