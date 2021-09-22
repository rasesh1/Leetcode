class Solution {
public:
    int search(vector<int>& A, int target) {
        int n = A.size();
        
        int left=0, right=n-1;
        
        while(left <= right)    {
            if(left == right) return (A[left] == target ? left : -1);
            if(right-left == 1) {
                if(A[left] == target) return left;
                else return (A[right] == target ? right : -1);
            }
                
            int mid = left + (right-left)/2;
            
            if(A[mid] == target) return mid;
            
            // Pivot on right side of mid
            if(A[mid-1] >= A[left]) {
                if(A[left] <= target && A[mid-1] >= target) {
                    right = mid-1;
                else 
                    left = mid+1;
            }
            
            // Pivot on left side of mid
            else {
                if(A[right] >= target && A[mid+1] <= target)
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return -1;
    }
};