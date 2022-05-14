class Solution {
public:
    int maxA(int n) {
        if(n <= 3) return n;
        
        vector<int> A(n+1,0);
        
        A[0] = 0; A[1] = 1;
        A[2] = 2; A[3] = 3;
        
        for(int i=4; i<=n; i++) {
            A[i] = A[i-1] + 1;
            for(int j=i-3; j>=1; j--)
                A[i] = max(A[i], (A[j]*(i-3-j+2)));
        }
        return A[n];
    }
};