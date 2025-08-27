class Solution {
public:
    string interpret(string command) {
        int n = command.size();
        string s = "";
        for (int i = 0; i < n - 1; i++) {
            if (command[i] == '(' && command[i+1] == ')') {
                s += 'o';
            }
            else if ((command[i] == '(' && command[i+1] != ')') || command[i] == ')') {
                continue;
            }
            else {
                s += command[i];
            }
        }
        if (isalpha(command[n-1])) s += command[n-1];
        return s;
    }
};
