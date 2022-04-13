class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> A(3, vector<int>(n+1,0));
        
        // Base Case - 1st row
        for(int j=0; j<=n; j++) A[1][j] = j;
        
        // Base Case - 1 floor
        for(int j=0; j<=2; j++) A[j][1] = 1;
        
        for(int j=2; j<=n; j++) {
            int mini = INT_MAX;
            for(int mj=j-1, pj=0; mj>=0; mj--, pj++)    {
                int maxi = max(A[2][mj], A[1][pj]);
                mini = min(mini, maxi);
            }
            A[2][j] = mini+1;
        }
        return A[2][n];
    }
};