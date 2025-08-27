class Solution {
public:
    string convertDateToBinary(string date) {
        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,2));
        int d = stoi(date.substr(8,2));

        string by = bitset<32>(y).to_string();
        by = by.substr(by.find('1'));

        string bm = bitset<8>(m).to_string();
        bm = bm.substr(bm.find('1'));

        string bd = bitset<8>(d).to_string();
        bd = bd.substr(bd.find('1'));

        return by + "-" + bm + "-" + bd;
    }
};
