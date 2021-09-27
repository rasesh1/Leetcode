class Solution {
public:
    int numTrees(int n) {
        if(n <= 2) return n;
        
        int A[n+1];
        A[0]=1; A[1]=1; A[2]=2;
        
        for(int i=3; i<=n; i++) {
            A[i] = 0;
            for(int j=0; j<i; j++)  {
                A[i] = A[i] + A[j]*A[i-j-1];
            }
        }
        return A[n];
    }
};