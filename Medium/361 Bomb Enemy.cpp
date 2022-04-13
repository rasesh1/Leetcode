typedef pair<int,int> pi;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int maxi = 0;
        vector<vector<pi>> A(rows+1, vector<pi>(cols+1, make_pair(0,0) ));
        vector<vector<pi>> B(rows+1, vector<pi>(cols+1, make_pair(0,0) ));
        
        for(int i=0; i<rows; i++)   {
            for(int j=0; j<cols; j++)   {
                if(grid[i][j] == 'W') continue;
                
                A[i+1][j+1].first = A[i+1][j].first;
                A[i+1][j+1].second = A[i][j+1].second;
                
                if(grid[i][j] == 'E')   {
                    A[i+1][j+1].first++;
                    A[i+1][j+1].second++;
                }
            }
        }
        
        for(int i=rows-1; i>=0; i--)   {
            for(int j=cols-1; j>=0; j--)   {
                if(grid[i][j] == 'W') continue;
                
                B[i][j].first = B[i][j+1].first;
                B[i][j].second = B[i+1][j].second;
                
                if(grid[i][j] == 'E')   {
                    B[i][j].first++;
                    B[i][j].second++;
                }
                if(grid[i][j] == '0')
                    maxi = max(maxi, B[i][j].first+A[i+1][j+1].first+B[i][j].second+A[i+1][j+1].second);
            }
        }
        return maxi;
    }
};