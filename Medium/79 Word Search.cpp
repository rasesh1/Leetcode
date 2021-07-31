class Solution {
private:
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int index, int i, int j)    {
        
        bool ans = false;
        if(index == word.length())
            return true;
        
        if(i-1>=0 && !visited[i-1][j] && board[i-1][j] == word[index])  {
            visited[i-1][j] = 1;
            ans = dfs(board,visited,word,index+1, i-1, j);
            visited[i-1][j] = 0;
            if(ans) return true;
        }
        
        if(j-1>=0 && !visited[i][j-1] && board[i][j-1] == word[index])  {
            visited[i][j-1] = 1;
            ans = dfs(board,visited,word,index+1, i, j-1);
            visited[i][j-1] = 0;
            if(ans) return true;
        }
        
        if(i+1<board.size() && !visited[i+1][j] && board[i+1][j] == word[index])  {
            visited[i+1][j] = 1;
            ans = dfs(board,visited,word,index+1, i+1, j);
            visited[i+1][j] = 0;
            if(ans) return true;
        }
        
        if(j+1<board[0].size() && !visited[i][j+1] && board[i][j+1] == word[index])  {
            visited[i][j+1] = 1;
            ans = dfs(board,visited,word,index+1, i, j+1);
            visited[i][j+1] = 0;
            if(ans) return true;
        }
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.length();
        
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<int>> visited(rows, vector<int>(cols,0));
        
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                
                if(board[i][j] == word[0])  {
                    visited[i][j] = 1;
                    bool ans = dfs(board, visited, word, 1, i, j);
                    if(ans) return true;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};