class Solution {
public:
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<double>> A(n, vector<double>(n,0));
        
        if(row == n || col == n) return 0;
        if(k == 0) return 1;
        
        A[row][col] = 1;
        vector<int> hor_dir = {-2,-1,1,2,2,1,-1,-2};
        vector<int> ver_dir = {1,2,2,1,-1,-2,-2,-1};
        
        for(int m=1; m<=k; m++)  {
            
            vector<vector<double>> B(n, vector<double>(n,0));
            for(int i=0; i<n; i++)  {
                for(int j=0; j<n; j++)  {
                    
                    for(int a=0; a<8; a++)  {
                        int r = i + hor_dir[a];
                        int c = j + ver_dir[a];
                        
                        if(r<0 || c<0 || r>=n || c>=n) continue;
                        
                        B[r][c] = B[r][c] + A[i][j]/8.0;
                    }
                }
            }
            A = B;
        }
        
        double ans = 0;
        for(int i=0; i<n; i++)  {
            for(int j=0; j<n; j++)  {
                ans = ans + A[i][j];
            }
        }
        return ans;
    }
};