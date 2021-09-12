class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        
        int A[n+1];
        A[0]=0; A[1]=1; A[2]=2;
        for(int i=3; i<=n; i++)
            A[i]=A[i-1]+A[i-2];
        return A[n];
    }
};