class Solution {
private:
    vector<vector<string>> ans;
    void placeQueen(vector<vector<char>>& current, int a, int b, int n) {
        vector<int> xs = {-1,0,1,1,1,0,-1,-1};
        vector<int> ys = {1,1,1,0,-1,-1,-1,0};
        
        current[a][b] = 'Q';
        
        for(int i=0; i<8; i++)  {
            int x = a + xs[i];
            int y = b + ys[i];
            while(x>=0 && x<n && y>=0 && y<n)   {
                current[x][y] = char(current[x][y] + 1);
                x = x + xs[i];
                y = y + ys[i];
            }
        }
        return;
    }
    
    void removeQueen(vector<vector<char>>& current, int a, int b, int n) {
        vector<int> xs = {-1,0,1,1,1,0,-1,-1};
        vector<int> ys = {1,1,1,0,-1,-1,-1,0};
        
        current[a][b] = '0';
        
        for(int i=0; i<8; i++)  {
            int x = a + xs[i];
            int y = b + ys[i];
            while(x>=0 && x<n && y>=0 && y<n)   {
                current[x][y] = char(current[x][y] - 1);
                x = x + xs[i];
                y = y + ys[i];
            }
        }
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
            if(current[row][i] == '0')    {
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