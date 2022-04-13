class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> A(k+1, vector<int>(n+1, 0));
        
        // Base Case - 1 egg
        for(int j=0; j<=n; j++) A[1][j] = j;
        
        // Base Case - 1 floor
        for(int j=0; j<=k; j++) A[j][1] = 1;
        
        for(int i=2; i<=k; i++) {
            for(int j=2; j<=n; j++) {
                int mini = INT_MAX;
                for(int mj=j-1, pj=0; mj>=0; mj--,pj++) {
                    int maxi = max(A[i][mj], A[i-1][pj]);
                    mini = min(maxi, mini);
                }
                A[i][j] = mini+1;
            }
        }
        return A[k][n];
    }
};