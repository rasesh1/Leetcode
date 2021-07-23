class Solution {
private:
    vector<vector<string>> ans;
    unordered_set<int> cols,rows,diags,antidiags;
    
    void placeQueen(vector<vector<char>>& current, int a, int b, int n) {
        vector<int> xs = {-1,0,1,1,1,0,-1,-1};
        vector<int> ys = {1,1,1,0,-1,-1,-1,0};
        
        current[a][b] = 'Q';
        
        rows.insert(a);
        cols.insert(b);
        diags.insert(b-a);
        antidiags.insert(b+a);
        return;
    }
    
    void removeQueen(vector<vector<char>>& current, int a, int b, int n) {
        vector<int> xs = {-1,0,1,1,1,0,-1,-1};
        vector<int> ys = {1,1,1,0,-1,-1,-1,0};
        
        current[a][b] = '0';
        
        rows.erase(a);
        cols.erase(b);
        diags.erase(b-a);
        antidiags.erase(b+a);
        return;
    }
    
    void computePositions(vector<vector<char>>& current, int row, int n)   {
        if(row == n)    {
            vector<string> temp;
            for(int i=0; i<current.size(); i++)    {
                string xxx = "";
                for(int j=0; j<current[0].size(); j++) {
                    if(current[i][j] != 'Q') xxx = xxx + ".";
                    else xxx = xxx + "Q";
                }
                temp.push_back(xxx);
            }
            ans.push_back(temp);
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
        string defaulty(n, '0');
        vector<vector<char>> current(n, vector<char>(n,'0'));
        if(n == 1) return {{"Q"}};
        
        computePositions(current, 0, n);
        
        return ans;
    }
};