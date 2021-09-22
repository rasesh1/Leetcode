class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        int rows = A.size();
        int cols = A[0].size();
        
        int left=0, right=rows*cols-1;
        
        while(left <= right)    {
            int lr = left/cols;
            int lc = left%cols;
            
            int rr = right/cols;
            int rc = right%cols;
            
            if(right-left <= 1) return (A[lr][lc]==target || target==A[rr][rc]);
            
            int mid = left + (right-left)/2;
            
            int row = mid/cols;
            int col = mid%cols;
            
            if(A[row][col] == target) return true;
            else if(A[row][col] > target) right = mid-1;
            else left = mid+1;
        }
        return false;
    }
};