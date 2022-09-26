class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int sum = 0;
        for(auto s : stones) sum = sum + s;
        
        int req = sum/2;
        
        vector<vector<int>> A(n, vector<int>(req+1,0));
        
        // First Row
        for(int j=1; j<=req; j++)
            A[0][j] = (j>=stones[0] ? stones[0] : 0);
        
        for(int i=1; i<n; i++)  {
            for(int j=1; j<=req; j++)   {
                int val = stones[i];
                int wt = stones[i];
                
                int notInclude = A[i-1][j];
                
                int include = 0;
                if(j-wt>=0) include = val + A[i-1][j-wt];
                
                A[i][j] = max(include, notInclude);
            }
        }
        
        return sum - 2*A[n-1][req];
    }
};