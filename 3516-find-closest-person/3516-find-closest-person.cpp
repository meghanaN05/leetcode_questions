class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a1=abs(x-z);
        int a2=abs(y-z);
        if(a1<a2) return 1;
        if(a1>a2) return 2;
        return 0;
    }
};