class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n < 2) return min(cost[0], cost[1]);
        
        int A[n+1];
        A[0]=cost[0]; A[1]=cost[1];
        
        for(int i=2; i<n; i++)  {
            A[i] = min(A[i-1], A[i-2]) + cost[i];
        }
        return min(A[n-1], A[n-2]);
    }
};