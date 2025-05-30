class Solution {
public:
    string result = "";

 
    void helper(int k, string current) {
        if (current.size() >= k) {
            result = current;
            return;
        }

        string nextPart = "";
        for (char c : current) {
           
            char nextChar = (c == 'z') ? 'a' : c + 1;
            nextPart += nextChar;
        }

        helper(k, current + nextPart);
    }

    char kthCharacter(int k) {
        helper(k, "a");
        return result[k - 1]; 
    }
};
