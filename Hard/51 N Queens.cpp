typedef vector<vector<string>> vvs;
typedef vector<string> vs;

class Solution {
private:
    vvs ans;
    unordered_set<int> rows,cols,diag,antidiag;
    
    bool canPlace(int i, int j) {
        if(rows.find(i) != rows.end()) return false;
        if(cols.find(j) != cols.end()) return false;
        if(diag.find(i-j) != diag.end()) return false;
        if(antidiag.find(i+j) != antidiag.end()) return false;
        
        return true;
    }
    
    void placeQueen(int i, int j, vs& curr) {
        curr[i][j] = 'Q';
        rows.insert(i); cols.insert(j); diag.insert(i-j); antidiag.insert(i+j);
        return;
    }
    
    void removeQueen(int i, int j, vs& curr)    {
        curr[i][j] = '.';
        rows.erase(i); cols.erase(j); diag.erase(i-j); antidiag.erase(i+j);
        return;
    }
    
    void backtrack(int row, vs& curr, int n)    {
        if(row == n)   {
            ans.push_back(curr);
            return;
        }
        
        int i=row;
        for(int j=0; j<n; j++)    {
            bool possible = canPlace(i, j);
            if(possible)    {
                placeQueen(i, j, curr);
                backtrack(i+1, curr, n);
                removeQueen(i, j, curr);
            }
        }
        return;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vs curr = vector<string>(n, std::string(n, '.'));
        backtrack(0, curr, n);
        return ans;
    }
};