class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        
        if((n-1)%(K-1) != 0) return -1;
        
        vector<int> prefix(n+1,0);
        for(int i=0; i<n; i++)
            prefix[i+1] = prefix[i] + stones[i];
        
        vector<vector<int>> A(n, vector<int>(n,0));
        
        for(int delta=K-1; delta<n; delta++)    {
            for(int j=0; j+delta<n; j++)    {
                int x = j;
                int y = j+delta;
                
                A[x][y] = INT_MAX;
                for(int k=x; k<y; k=k+K-1)    {
                    A[x][y] = min(A[x][y], A[x][k]+A[k+1][y]);
                }
                if(delta%(K-1) == 0) A[x][y] = A[x][y] + prefix[y+1]-prefix[x];
            }
        }
        return A[0][n-1] == INT_MAX ? -1 : A[0][n-1];
    }
};