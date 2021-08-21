typedef vector<vector<char>> vvc;

class Solution {
private:
    bool checkRows(vvc& board)  {
        for(int i=0; i<9; i++)  {
            vector<int> mp(10,0);
            for(int j=0; j<9; j++)  {
                if(board[i][j] == '.') continue;
                
                else    {
                    int num = (int)(board[i][j] - '0');
                    if(mp[num] == 1) return false;
                    else mp[num] = 1;
                }
            }
        }
        return true;
    }
    
    bool checkCols(vvc& board)  {
        for(int i=0; i<9; i++)  {
            vector<int> mp(10,0);
            for(int j=0; j<9; j++)  {
                if(board[j][i] == '.') continue;
                
                else    {
                    int num = (int)(board[j][i] - '0');
                    if(mp[num] == 1) return false;
                    else mp[num] = 1;
                }
            }
        }
        return true;
    }
    
    bool checkSquares(vvc& board)  {
        for(int k=0; k<9; k++)  {
            vector<int> mp(10,0);
            
            int x = (k/3)*3;
            int y = (k%3)*3;
            
            for(int i=x; i<=x+2; i++)   {
                for(int j=y; j<=y+2; j++)   {
                    if(board[i][j] == '.') continue;
                    
                    else    {
                        int num = (int)(board[i][j] - '0');
                        if(mp[num] == 1) return false;
                        else mp[num] = 1;
                    }
                }
            }
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRows(board) && checkCols(board) && checkSquares(board);
    }
};