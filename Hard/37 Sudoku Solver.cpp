typedef vector<vector<char>> vvc;

class Solution {
private:
    vector<vector<int>> rows{9, vector<int>(10,0)};
    vector<vector<int>> cols{9, vector<int>(10,0)};
    vector<vector<int>> blocks{9, vector<int>(10,0)};
    
    bool isPossible(char n, vvc& board, int row, int col)  {
        int ind = (row/3)*3 + col/3;
        return rows[row][n-'0'] == 0 && cols[col][n-'0'] == 0 && blocks[ind][n-'0'] == 0;
    }
    
    bool backtrack(vvc& board, int start_row, int start_col)    {
        
        if(start_row == 9)    {
            return true;
        }
        
        if(start_col == 9)
            return backtrack(board, start_row+1, 0);
        
        char val = board[start_row][start_col];
        int ind = (start_row/3)*3 + start_col/3;
        
        if(board[start_row][start_col] != '.')  {
            return backtrack(board, start_row, start_col+1);
        }
            
                
        for(int n='1'; n<='9'; n++) {

            bool CanPlace = isPossible(n, board, start_row, start_col);
            if(CanPlace)    {
                board[start_row][start_col] = n;
                
                rows[start_row][n-'0'] = 1;
                cols[start_col][n-'0'] = 1;
                blocks[ind][n-'0'] = 1;

                bool temp = backtrack(board, start_row, start_col+1);
                
                if(temp) return true;
                else board[start_row][start_col] = '.';
                
                rows[start_row][n-'0'] = 0;
                cols[start_col][n-'0'] = 0;
                blocks[ind][n-'0'] = 0;
            }
        }
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++)  {
            for(int j=0; j<9; j++)  {
                if(board[i][j] != '.')  {
                    int ind = (i/3)*3 + j/3;
                    char n = board[i][j];
                    
                    rows[i][n-'0'] = 1;
                    cols[j][n-'0'] = 1;
                    blocks[ind][n-'0'] = 1;
                }
            }
        }
        
        backtrack(board, 0, 0);
        return;
    }
};