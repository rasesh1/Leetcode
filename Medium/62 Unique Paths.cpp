class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        
        int A[m][n];
        for(int i=0; i<m; i++) A[i][0]=1;
        for(int i=0; i<n; i++) A[0][i]=1;
        
        for(int i=1; i<m; i++)  {
            for(int j=1; j<n; j++)
                A[i][j] = A[i-1][j] + A[i][j-1];
        }
        return A[m-1][n-1];
    }
};