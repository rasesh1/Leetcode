class Solution {
private:
    int ans=0;
    unordered_set<int> rows,cols,diags,antidiags;

    void placeQueen(vector<vector<char>>& current, int a, int b, int n)	{ 
        current[a][b] = 'Q';
        rows.insert(a);
        cols.insert(b);
        diags.insert(b-a);
        antidiags.insert(b+a);
        return;
    }

    void removeQueen(vector<vector<char>>& current, int a, int b, int n)	{ 
        current[a][b] = '0';
        rows.erase(a);
        cols.erase(b);
        diags.erase(b-a);
        antidiags.erase(b+a);
        return;
    }

    void computePositions(vector<vector<char>>& current, int row, int n)	{ 
        if(row == n)	{ 
            ans++;
            return;
        }

        for(int i=0; i<n; i++)	{ 
            bool b1 = (rows.find(row) == rows.end()) ? false : true;
            bool b2 = (cols.find(i) == cols.end()) ? false : true;
            bool b3 = (diags.find(i-row) == diags.end()) ? false : true;
            bool b4 = (antidiags.find(i+row) == antidiags.end()) ? false : true;

            if(!b1 && !b2 && !b3 && !b4)	{
                placeQueen(current, row, i, n);
                computePositions(current, row+1, n);
                removeQueen(current, row, i, n);
            }
        }
        return;
    }

    
public:
    int totalNQueens(int n) {
        if(n == 1) return 1;
        
        vector<vector<char>> current(n, vector<char>(n, '0'));
	    computePositions(current, 0, n);
        return ans;

    }
};