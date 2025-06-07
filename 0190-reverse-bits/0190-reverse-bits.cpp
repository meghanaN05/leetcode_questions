class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int rev = 0;
        for (int i = 0; i < 32; i++){
            if ((n >> i) & 1){
                cout << i << endl;
                rev |= (1 << (31 - i));
            }
        }       
        return rev;
    }
};