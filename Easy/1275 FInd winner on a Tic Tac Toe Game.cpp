typedef vector<vector<int>> vvi;

class Solution {
private:
    bool checkRow(int r, vvi& board, int val)   {
        for(int i=0; i<3; i++)  {
            if(board[r][i] != val) return false;
        }
        return true;
    }
    
    bool checkCol(int c, vvi& board, int val)   {
        for(int i=0; i<3; i++)  {
            if(board[i][c] != val) return false;
        }
        return true;
    }
    
    bool checkDiag(vvi& board, int val)   {
        for(int i=0; i<3; i++)  {
            if(board[i][i] != val) return false;
        }
        return true;
    }
    
    bool checkAntiDiag(vvi& board, int val)   {
        for(int i=0; i<3; i++)  {
            if(board[2-i][i] != val) return false;
        }
        return true;
    }
    
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        vector<vector<int>> board(3, vector<int>(3,-1));
        
        int i;
        for(i=0; i<n; i++)  {
            vector<int> move = moves[i];
            int x = move[0];
            int y = move[1];
            
            board[x][y] = (i%2);
            
            bool row = checkRow(x, board, i%2);
            bool col = checkCol(y, board, i%2);
            
            if(row || col) return (0 == i%2 ? "A" : "B");
            
            if(x == y)  {
                if(checkDiag(board, i%2)) return (0 == i%2 ? "A" : "B");
            }
            if(x+y == 2)   {
                if(checkAntiDiag(board, i%2)) return (0 == i%2 ? "A" : "B");
            }
        }
        
        return (i == 9 ? "Draw" : "Pending");
    }
};