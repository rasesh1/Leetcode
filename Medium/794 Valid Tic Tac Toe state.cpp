class Solution {
private:
    int rows, cols;
    bool isWinning(vector<string>& board, int i, int j) {
        char c = board[i][j];
        
        // Row
        if(board[i][j] == board[i][0] && board[i][j] == board[i][1] && board[i][j] == board[i][2])
            return true;
        
        // Column
        if(board[i][j] == board[0][j] && board[i][j] == board[1][j] && board[i][j] == board[2][j])
            return true;
        
        // Diag
        if(i == j)  {
            if(board[i][j] == board[0][0] && board[i][j] == board[1][1] && board[i][j] == board[2][2])
                return true;
        }
        
        // Reverse Diag
        if(i + j == 2)  {
            if(board[i][j] == board[0][2] && board[i][j] == board[1][1] && board[i][j] == board[2][0])
                return true;
        }
        return false;
    }
    
public:
    bool validTicTacToe(vector<string>& board) {
        rows = board.size();
        cols = board[0].size();
        
        int Xwin = 0, Owin = 0;
        int diff = 0;
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(board[i][j] == ' ') continue;
                
                bool winning = isWinning(board, i ,j);
                
                if(board[i][j] == 'X')  {
                    diff++;
                    if(winning) Xwin++;
                }
                else {
                    diff--;
                    if(winning) Owin++;
                }
            }
        }
        
        if(diff < 0 || diff > 1 || Xwin >= 6 || Owin >= 6 || (Xwin > 0 && Owin > 0) ) return false;
        if( (diff == 0 && Xwin > 0) || (diff == 1 && Owin > 0) ) return false;
        return true;
    }
};