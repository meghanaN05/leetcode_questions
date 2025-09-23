class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n = version1.size(), m = version2.size();

        while (i < n || j < m) {
            int index1 = version1.find('.', i);
            string s = (index1 == string::npos) ? version1.substr(i) : version1.substr(i, index1 - i);
            int index2 = version2.find('.', j);
            string t = (index2 == string::npos) ? version2.substr(j) : version2.substr(j, index2 - j);

        
            int num1 = s.empty() ? 0 : stoi(s);
            int num2 = t.empty() ? 0 : stoi(t);

            if (num1 > num2) return 1;
            if (num1 < num2) return -1;

            
            i = (index1 == string::npos) ? n : index1 + 1;
            j = (index2 == string::npos) ? m : index2 + 1;
        }

        return 0;
    }
};
