class Spreadsheet {
public:
 vector<vector<int>> sheet;
 int solve(string &s) {
        if(isdigit(s[0])) {
            return stoi(s);
        }

        int col = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1;

        return sheet[row][col];
    }
    Spreadsheet(int rows) {
        
        sheet.assign(rows, vector<int>(26, 0));  
    }
    
    void setCell(string cell, int value) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1))-1;
        sheet[row][col]=value;
    }
    
    void resetCell(string cell) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1))-1;
         sheet[row][col]=0;
    }
    
    int getValue(string formula) {
        string result=formula.substr(1);
        int index=result.find('+');
        string a=result.substr(0,index);
        string b=result.substr(index+1);
        return solve(a)+solve(b);

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */