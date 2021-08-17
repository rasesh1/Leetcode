class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        
        int A[n][n];
        
        // Base Cases
        A[n-1][n-1] = 1;
        for(int i=0; i<n-1; i++)    {
            A[i][i] = 1;
            A[i][i+1] = 2;
            if(s[i] != s[i+1]) A[i][i+1] = 1;
        }
        
        for(int i=2; i<n; i++)  {
            for(int j=0; i+j<n; j++)  {
                int x = j, y=i+j;
                
                if(s[x] == s[y])    {
                    A[x][y] = 2+A[x+1][y-1];
                }
                else    {
                    A[x][y] = max(A[x+1][y], A[x][y-1]);
                }
            }
        }
        return A[0][n-1];
    }
};