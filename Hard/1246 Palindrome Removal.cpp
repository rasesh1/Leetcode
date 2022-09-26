class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> A(n, vector<int>(n,0));
        
        // Diagonal
        for(int i=0; i<n; i++) A[i][i] = 1;
        
        // Second diagonal
        for(int i=0; i<n-1; i++)    {
            if(arr[i] == arr[i+1]) A[i][i+1] = 1;
            else A[i][i+1] = 2;
        }
        
        for(int delta=2; delta<n; delta++)  {
            for(int i=0; i+delta<n; i++)    {
                int j = i + delta;
                
                if(arr[i] == arr[j]) A[i][j] = A[i+1][j-1];
                else    {
                    A[i][j] = 1 + min(A[i+1][j], A[i][j-1]);
                    A[i][j] = min(A[i][j], A[i+1][j-1] + 2);
                    
                    for(int k=i; k<j; k++)
                        A[i][j] = min(A[i][j], A[i][k]+A[k+1][j]);
                }
            }
        }
        return A[0][n-1];
    }
};