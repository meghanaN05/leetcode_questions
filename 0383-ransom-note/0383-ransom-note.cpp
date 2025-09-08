class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> m; 
        
        for(int i=0; i<magazine.size(); i++){
            m[magazine[i]-'a']++;
        }
        for(int i=0; i<ransomNote.size(); i++){
            if(m[ransomNote[i]-'a'] > 0){
                m[ransomNote[i]-'a']--;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};
