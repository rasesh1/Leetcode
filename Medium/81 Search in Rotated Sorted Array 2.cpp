class Solution {
public:
    bool search(vector<int>& A, int target) {
        int n = A.size();
        
        int left=0, right=n-1;
        
        while(left <= right)    {
            
            if(left == right) return A[left] == target;
            if(right - left == 1) return A[left] == target || A[right] == target;
            
            if(A[right] == A[left]) {
                right--;
                continue;
            }
            
            int mid = left + (right-left)/2;
            if(A[mid] == target) return mid;
                
            // Pivot in left side
            if(A[mid+1] <= A[right])    {
                if(A[mid+1] <= target && A[right] >= target)
                    left = mid+1;
                else
                    right = mid-1;
            }
            
            // Pivot on right side
            else    {
                if(A[left] <= target && A[mid-1] >= target)
                    right = mid-1;
                else
                    left = mid+1;
            }
            
        }
        return -1;
    }
};