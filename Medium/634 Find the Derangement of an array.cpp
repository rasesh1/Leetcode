class Solution {
public:
    int findDerangement(int n) {
        int MOD = 1000000007;
        vector<long long int> A(n+1,0);
        
        if(n <= 3) return n-1;
        
        A[1] = 0;
        A[2] = 1;
        A[3] = 2;
        
        for(int i=4; i<=n; i++) {
            A[i] = ((i-1)* (A[i-1]+A[i-2]) )%MOD;
        }
        return A[n];
    }
};