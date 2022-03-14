class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        
        vector<vector<int>> A(n+1, vector<int>(k,INT_MAX));
        int miniIndex = 0;
        int second_miniIndex = 0;
        
        for(int j=0; j<k; j++) A[0][j] = 0;
        
        for(int i=0; i<n; i++)  {
            int prevMini = miniIndex, prev_second_mini = second_miniIndex;
            
            miniIndex = k-1;
            second_miniIndex = k-1;
            
            for(int j=0; j<k; j++)  {
                A[i+1][j] = costs[i][j] + A[i][prevMini];
                if(j == prevMini) A[i+1][j] = costs[i][j] + A[i][prev_second_mini];
                
                if(A[i+1][j] <= A[i+1][miniIndex])  {
                    second_miniIndex = miniIndex;
                    miniIndex = j;
                }
                else if(A[i+1][j] < A[i+1][second_miniIndex])  {
                    second_miniIndex = j;
                }
            }
        }
        return A[n][miniIndex];
    }
};