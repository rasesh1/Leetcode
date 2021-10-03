class Solution {
public:
    int searchInsert(vector<int>& A, int target) {
        int n = A.size();
        if(n == 0) return 0;
        
        int left = 0, right=n-1;
        while(left <= right)    {
            
            int mid = left + (right-left)/2;
            if(A[mid] == target) return mid;
            
            else if(A[mid] < target)
                left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};