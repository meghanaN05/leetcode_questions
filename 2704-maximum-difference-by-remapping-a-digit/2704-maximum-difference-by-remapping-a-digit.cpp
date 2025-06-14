class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        
       
        string max_s = s;
        char to_replace_max = ' ';
        for (char c : s) {
            if (c != '9') {
                to_replace_max = c;
                break;
            }
        }
        if (to_replace_max != ' ') {
            for (char& c : max_s) {
                if (c == to_replace_max) c = '9';
            }
        }
        
       
        string min_s = s;
        char to_replace_min = s[0]; 
        for (char& c : min_s) {
            if (c == to_replace_min) c = '0';
        }

        int max_val = stoi(max_s);
        int min_val = stoi(min_s);

        return max_val - min_val;
    }
};
