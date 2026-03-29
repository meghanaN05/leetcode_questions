class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2) return true;
        int i=0;
        int j=2;
        while(j!=s1.size()){
            if(s1[i]!=s2[i])
            swap(s1[i],s1[j]);
            i++;
            j++;
        }
        return s1==s2;
    }
};