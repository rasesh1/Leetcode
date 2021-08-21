class Solution {
public:
    int minCost(vector<vector<int>>& A) {
        int n = A.size();

        vector<vector<int>> ans(n, vector<int>(3,0));

        // Base Case
        ans[0][0] = A[0][0];
        ans[0][1] = A[0][1];
        ans[0][2] = A[0][2];

        for(int i=1; i<n; i++)  {
            ans[i][0] = min(ans[i-1][1], ans[i-1][2]) + A[i][0];
            ans[i][1] = min(ans[i-1][0], ans[i-1][2]) + A[i][1];
            ans[i][2] = min(ans[i-1][1], ans[i-1][0]) + A[i][2];
        }

        return min(min(ans[n-1][0], ans[n-1][1]), ans[n-1][2]);
    }
};