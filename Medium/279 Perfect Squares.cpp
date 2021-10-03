class Solution {
public:
    int numSquares(int n) {
        if(n == 1) return 1;
        
        int A[n+1];
        A[0]=0; A[1]=1;
        
        for(int i=2; i<=n; i++) {
            int j=1;
            A[i] = INT_MAX;
            while(i-j*j >= 0)   {
                A[i] = min(A[i], 1+A[i-j*j]);
                j++;
            }
        }
        return A[n];
    }
};