class Solution {
private:
    vector<vector<string>> ans;
    unordered_set<int> cols,rows,diags,antidiags;
    
    void placeQueen(vector<string>& current, int a, int b, int n) {
        
        current[a][b] = 'Q';
        
        rows.insert(a);
        cols.insert(b);
        diags.insert(b-a);
        antidiags.insert(b+a);
        return;
    }
    
    void removeQueen(vector<string>& current, int a, int b, int n) {
        
        current[a][b] = '.';
        
        rows.erase(a);
        cols.erase(b);
        diags.erase(b-a);
        antidiags.erase(b+a);
        return;
    }
    
    void computePositions(vector<string>& current, int row, int n)   {
        if(row == n)    {
            ans.push_back(current);
            return;
        }
        
        for(int i=0; i<current[row].size(); i++)    {
            bool b1 = (rows.find(row) == rows.end()) ? false : true;
            bool b2 = (cols.find(i) == cols.end()) ? false : true;
            bool b3 = (diags.find(i-row) == diags.end()) ? false : true;
            bool b4 = (antidiags.find(i+row) == antidiags.end()) ? false : true;
            
            if( !b1 && !b2 && !b3 && !b4 )    {
                placeQueen(current, row, i, n);
                computePositions(current, row+1, n);
                removeQueen(current, row, i, n);
            }
        }
        return;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        string defaulty(n, '.');
        vector<string> current(n, defaulty);
        if(n == 1) return {{"Q"}};
        
        computePositions(current, 0, n);
        
        return ans;
    }
};