class Solution {
private:
    int findFirstOccurence(vector<int>& A, int target)   {
        int n = A.size();
        int left=0, right=n-1;
        
        while(left <= right)    {
            if(left == right) return A[left]==target ? left : -1;
            
            int mid = left + (right-left)/2;
            
            if(A[mid] == target) right = mid;
            else if(A[mid] > target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
    
    int findLastOccurence(vector<int>& A, int target)   {
        int n = A.size();
        int left=0, right=n-1;
        
        while(left <= right)    {
            if(left == right) return A[left]==target ? left : -1;
            
            int mid = right - (right-left)/2;
            
            if(A[mid] == target) left = mid;
            else if(A[mid] > target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int first = findFirstOccurence(nums, target);
        int last = findLastOccurence(nums, target);
        return {first,last};
    }
};