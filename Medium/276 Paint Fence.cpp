class Solution {
public:
    int numWays(int n, int k) {
        if(n==1) return k;
        
        int A[n+1];
        A[0] = 1;
        A[1] = k;
        A[2] = k*k;
        
        for(int i=3; i<=n; i++) {
            A[i] = A[i-1]*(k-1) + A[i-2]*(k-1);
        }
        return A[n];
    }
};