class Solution {
private:
    vector<int> fillArray(vector<int>& A, int n)   {
        vector<int> ans(n,0);
        for(int i=0; i<n; i++)  {
            
            int k=n+i;
            while(k > 0) {
                ans[i] = ans[i] + A[k];
                k = k/2;
            }
        }
        return ans;
    }
    
public:
    vector<int> getModifiedArray(int n, vector<vector<int>>& updates) {
        vector<int> A(2*n, 0);
        
        for(auto update : updates) {
            int x = n+update[0];
            int y = n+update[1];
            int diff = update[2];
            
            A[x] = A[x] + diff;
            
            if(x == y) continue;
            A[y] = A[y] + diff;
            
            while(x/2 != y/2)   {
                if(x%2 == 0)    A[x+1] = A[x+1] + diff;
                if(y%2 == 1)    A[y-1] = A[y-1] + diff;
                
                x = x/2;
                y = y/2;
            }
        }
        
        vector<int> ans = fillArray(A, n);
        return ans;
    }
};