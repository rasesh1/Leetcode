class Solution {
public:
    int numberOfWays(int numPeople) {
        vector<long int> A(numPeople+1,0);
        A[0] = 1;
        A[2] = 1;
        int MOD = 1000000007;
        for(int i=4; i<=numPeople; i=i+2) {
            for(int j=1; j<=i-1; j=j+2)   {
                A[i] = (A[i] + A[j-1]*A[i-1-j]%MOD)%MOD;
            }
        }
        return A[numPeople];
    }
};1