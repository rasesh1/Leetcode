class Solution {
public:
    int integerBreak(int n) {
        vector<int> A(n+1,0);
        
        if(n <= 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        
        A[0] = 1;
        A[1] = 1;
        
        for(int i=2; i<=n; i++) {
            if(i%3 == 0) A[i] = 3*A[i-3];
            else A[i] = 2*A[i-2];
        }
        return A[n];
    }
};