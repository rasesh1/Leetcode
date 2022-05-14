class Solution {
private:
    int n;
    int k;
    int MOD = 1000000007;
    long long int recurse(int candlesRemain, int uniqueBagsUsed, vector<vector<int>>& A)    {
        if(candlesRemain == 0)  {
            if(uniqueBagsUsed == k)
                return 1;
            return 0;
        }
        
        if(A[candlesRemain][uniqueBagsUsed] != -1)
            return A[candlesRemain][uniqueBagsUsed];
        
        // Put in new Bag
        long long int val1 = 0;
        if(uniqueBagsUsed+1 <= k) val1 = recurse(candlesRemain-1, uniqueBagsUsed+1, A);
        
        // Put in used bag
        long long int val2 = (uniqueBagsUsed)* recurse(candlesRemain-1, uniqueBagsUsed, A);
        long long int ans = (val1 + val2)%MOD;
        A[candlesRemain][uniqueBagsUsed] = ans;
        return ans;
    }
    
public:
    int waysToDistribute(int n, int k) {
        this->n = n;
        this->k = k;
        
        if(n < k) return 0;
        if(n == k) return 1;
        
        vector<vector<int>> A(n+1, vector<int>(k+1,-1));
        recurse(n, 0, A);
        
        return A[n][0];
    }
};