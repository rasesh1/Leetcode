typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;

class Solution {
private:
    void dfs(vvc& board, int row, int col)  {
        board[row][col] = 'E';
        
        vector<int> xs = {0,1,0,-1};
        vector<int> ys = {1,0,-1,0};
        
        for(int k=0; k<4; k++)  {
            int r = row + xs[k];
            int c = col + ys[k];
            
            if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && board[r][c] == 'O')   {
                dfs(board, r, c);
            }
        }
        return;
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<m; i++)  {
            if(board[i][0] == 'O')  dfs(board, i, 0);
            
            if(board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        
        for(int i=0; i<n; i++)  {
            if(board[0][i] == 'O')  dfs(board, 0, i);
            
            if(board[m-1][i] == 'O') dfs(board, m-1, i);
        }
        
        for(int i=0; i<m; i++)  {
            for(int j=0; j<n; j++)  {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'E') board[i][j] = 'O';
            }
        }
        return;
    }
};