class Solution {
public:
    char kthCharacter(int k) {
  
    int flips = __builtin_popcount(k-1);

    return (char)('a' + flips);
}

};