class Solution {
private:
    int rows,cols;
public:
    long long maxPoints(vector<vector<int>>& points) {
        rows = points.size();
        cols = points[0].size();
        
        vector<long long int> A(cols,0);
        long long int ans = 0;
        for(int k=0; k<rows; k++)   {
            
            // Update A by iterating over columns
            for(int i=0; i<cols; i++)   {
                A[i] = A[i] + points[k][i];
                ans = max(ans,A[i]);
            }
            
            // Left traverse
            long long leftMax = A[0];
            for(int i=1; i<cols; i++)   {
                if(A[i] < leftMax) A[i] = --leftMax;
                else leftMax = A[i];
                ans = max(ans,A[i]);
            }
            
            long long rightMax = A[cols-1];
            for(int i=cols-2; i>=0; i--)   {
                if(A[i] < rightMax) A[i] = --rightMax;
                else rightMax = A[i];
                ans = max(ans,A[i]);
            }
        }
        return ans;
    }
};